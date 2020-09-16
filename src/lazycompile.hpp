#ifndef LAZYCOMPILE_H
#define LAZYCOMPILE_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "filemachine.hpp"
#include "term.h"

using namespace std;

void Run(string path);
string Compile(string gFlags, vector<string> objs, string outputPath, string outputName = "lazyout");
void MakeSO(string gFlags, vector<string> objs,string outputName = "lazyout");
vector<string> MakeObjects(string gFlags, vector<string> files,string outpath = "./",vector<string> flags = {""});
void Execute (string command);

#endif