//
// Created by bart on 6/7/15.
//

#include <array>
#include <sstream>
#include "cs2file.h"

const int getint(char *data) {
	return ((data[0] & 0xFF) << 24) | ((data[1] & 0xFF) << 16) | ((data[2] & 0xFF) << 8) | (data[3] & 0xFF);
}

const int getshort(char *data) {
	return ((data[0] & 0xFF) << 8) | (data[1] & 0xFF);
}

const std::string str(char *data) {
	char *p = data;
	while (*p != 0)
		p++;
	if (p - data == 0)
		return std::string("");
	return std::string(data, p - data);
}

cs2file::cs2file(std::vector<char> data) {
	// Parse the last 12 footer bytes
	char *buffer = &data[data.size() - 12];
	num_instr = getint(buffer); buffer += 4;
	num_int_params = getshort(buffer); buffer += 2;
	num_string_params = getshort(buffer); buffer += 2;
	num_int_locals = getshort(buffer); buffer += 2;
	num_string_locals = getshort(buffer);

	// Reset pointer to 0
	buffer = data.data();
	buffer += str(buffer).length() + 1;

	// Initialise the vectors
	instructions = std::vector<int>(num_instr);
	int_operands = std::vector<int>(num_instr);
	string_operands = std::vector<std::string>(num_instr);

	// Read script information
	int index = 0;
	while (buffer < &data[data.size() - 12]) {
		int instruction = getshort(buffer); buffer += 2;
		instructions[index] = instruction;

		if (instruction == 3) {
			string_operands[index] = str(buffer);
			buffer += string_operands[index].length() + 1;
		} else if (instruction < 100 && instruction != 21 && instruction != 38 && instruction != 39) {
			int_operands[index] = getint(buffer); buffer += 4;
		} else {
			int_operands[index] = *buffer++;
		}

		index++;
	}
}

std::string cs2file::disassemble() {
	std::stringbuf buffer;
	std::ostream os(&buffer);

	os << "// num_instructions: " << instructions.size() << "\n";
	os << "// num_int_params: " << num_int_params << "\n";
	os << "// num_string_params: " << num_string_params << "\n";
	os << "// num_int_locals: " << num_int_locals << "\n";
	os << "// num_string_locals: " << num_string_locals << "\n\n";

	for (int index = 0; index < instructions.size(); index++) {
		os << "#" << index << " = " << instructions[index]
		   << " (0x" << std::hex << instructions[index] << "), "
		   << std::dec << int_operands[index];

		if (!string_operands[index].empty()) {
			os << ", '" << string_operands[index] << "'";
		}

		os << "\n";
	}

	return buffer.str();
}
