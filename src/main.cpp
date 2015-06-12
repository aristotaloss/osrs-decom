#include <file_system.cc>
#include <boost/program_options.hpp>
#include <iostream>
#include "cs2file.h"

namespace po = boost::program_options;

int main(int ac, const char **av) {
	// Define the description and parameters
	po::options_description desc("osrs-decom: Old-School RuneScape script DECOMpiler\n(C) 2015 Bart Pelle\n\nProgram options");
	desc.add_options()
			("help", "display application help")
			("fs", po::value<string>()->required(), "specify filestore directory")
			("dasm", "disassemble instead of decompile")
			("debug", "print debug info while running")
			("script", po::value<int>()->required(), "script id to use")
			;

	// Set the non-optionified script id param
	po::positional_options_description p;
	p.add("script", 1);

	po::variables_map vm;
	po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
	po::notify(vm);

	bool debug = vm.count("debug") > 0;

	// Should we print out the application info?
	if (vm.count("help")) {
		std::cout << desc << '\n';
		std::cout << "Example:\n\tosrs-decom --fs \"/home/bart/osrs_data\" 619\n";
		return 0;
	}

	// Load the filesystem :)
	if (debug)
		std::cout << "Loading data from filestore '" << vm["fs"].as<string>() << "'...\n";

	FileSystem filesystem;
	filesystem.LoadDirectory(const_cast<char*>(vm["fs"].as<string>().c_str()));

	// Get data from fs
	std::vector<char> script_data;
	int sz = filesystem.GetIndex(12).GetDecompressed(vm["script"].as<int>(), script_data);

	if (debug)
		std::cout << "Script data size: " << sz << "\n";

	cs2file script(script_data);

	if (vm.count("dasm")) {
		std::cout << script.disassemble();
	}
	script.decompile();

	return 0;
}
