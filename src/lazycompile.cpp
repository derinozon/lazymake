#include "lazycompile.hpp"

string compiler = "g++";

namespace term {
	void H_ACTION (string msg) {
		cout << endl << BOLDBLUE << msg << endl << endl << RESET;
	}
	void P_ACTION (string msg) {
		cout << CYAN << msg << endl << RESET;
	}
	void P_SUCCESS (string msg) {
		cout << GREEN << msg << endl << RESET;
	}
	void STD (string msg) {
		cout << WHITE << msg << endl << RESET;
	}
	void ERR (int no) {
		cout << RED << "Error no: " << no << endl << RESET;
	}
}

string Connect (vector<string> items) {
	string ret = "";
	for (int i = 0; i < items.size(); i++) {
		ret += items[i];
		if (i != items.size()-1) ret += ' ';
	}
	return ret;
}
string Connect (string a, string b) {
	return a + ' ' + b;
}

vector<string> MakeObjects (string gFlags, vector<string> files,string outpath,vector<string> flags) {
	term::H_ACTION("Making Objects");
	
	string commandHead = Connect({compiler, gFlags, Connect(flags), "-c"});
	vector<string> objpaths;

	for (string file: files) {
		string fileName = GetFileName(file);
		string opath = ConnectPath(outpath, fileName+".o");
		string command = Connect({commandHead, file, "-o", opath});

		term::P_ACTION("Calling: " + command);
		
		Execute(command);
		objpaths.push_back(opath);

		term::P_SUCCESS("Created : " + opath);
	}

	return objpaths;
}

string Compile (string gFlags, vector<string> objs, string outputPath, string outputName) {
	term::H_ACTION("Compiling");
	string opath = ConnectPath(outputPath, outputName);
	string command = Connect({compiler, gFlags,Connect(objs), "-o", opath});

	term::P_ACTION("Calling: " + command);
	Execute(command);

	term::P_SUCCESS("Created: " + opath);
	return opath;
}

void MakeSO (string gFlags, vector<string> objs, string outputName) {
	string command = Connect({compiler,gFlags,Connect(objs),"-o",outputName});

	Execute(command);
}

void Run (string path) {
	term::H_ACTION("Running");
	term::STD("");

	Execute(path);
}

void Execute (string command) {
	int ret = system(command.c_str());
	if (ret != 0) {
		term::ERR(ret);
		exit(1);
	}
}