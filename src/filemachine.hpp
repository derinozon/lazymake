#ifndef FILEMACHINE_H
#define FILEMACHINE_H

#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

string ConnectPath (string a,string b);
void DeleteFile (string filePath);
void DeleteFiles (vector<string> files);
vector<string> GetAllFiles(string path,vector<string> extensions,bool recursive = false);
bool FileExists(string path);
void MakeDir (string path);
void MoveFile(string from,string to);
int GetFileEpoch(string path);
string GetFileName(string path);

#endif