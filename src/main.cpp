#include <cstring>

#include "lazycompile.hpp"

int main (int argc, char *argv[]) {
	string dir = ".";
	string gFlags = "";

	if (argv[1]) dir = argv[1];
	if (argv[2]) {
		if (!strcmp(argv[2], "11")) gFlags = "-std=c++11";
		if (!strcmp(argv[2], "14")) gFlags = "-std=c++14";
		if (!strcmp(argv[2], "17")) gFlags = "-std=c++17";
		if (!strcmp(argv[2], "2a")) gFlags = "-std=c++2a";
	}
	
	string mkDir = ConnectPath(dir,".lazymake");
	string cacheDir = ConnectPath(mkDir,".lazycache");

	if (!FileExists(mkDir)) MakeDir(mkDir);
	if (!FileExists(cacheDir)) MakeDir(cacheDir);
	
	vector<string> src = GetAllFiles(dir, {".cpp", ".c"});
	vector<string> objs = MakeObjects(gFlags, src, cacheDir, {"-fPIC"});

	string exe = Compile(gFlags, objs, mkDir);
	Run(exe);

	return 0;
}