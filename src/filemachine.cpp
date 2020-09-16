#include "filemachine.hpp"

string ConnectPath (string a, string b) {
	auto x = fs::path(a);
	auto y = fs::path(b);
	auto fnl = x/y;
	return fnl.string();
}

void DeleteFile (string filePath) {
	fs::remove(fs::path(filePath));
}

void DeleteFiles (vector<string> files) {
	for (string file : files) {
		DeleteFile(file);
	}
}

vector<string> GetAllFiles (string path,vector<string> extensions,bool recursive) {

	vector<string> finalList = {};

	if (recursive) {

	
    
		for (const auto& p: fs::recursive_directory_iterator(path)) {
			fs::path file = p.path();
			string fileExt = file.extension().string();

			for (string ext : extensions) {
				if (fileExt == ext) {
					finalList.push_back(file.string());
				}
			}
		}

	}
	else {


		for (const auto& p: fs::directory_iterator(path)) {
			fs::path file = p.path();
			string fileExt = file.extension().string();

			for (string ext : extensions) {
				if (fileExt == ext) {
					finalList.push_back(file.string());
				}
			}
		}



	}
    
	return finalList;
}

bool FileExists (string path) {
	return fs::exists(fs::path(path));
}

void MakeDir (string path) {
	fs::create_directory(path);
}

void MoveFile (string path,string to) {
	auto p = fs::path(path);
	
	fs::rename(p,to);
}

int GetFileEpoch (string path) {
	auto p = fs::path(path);
	auto t = fs::last_write_time(p);
	int e = t.time_since_epoch().count();
	return e;
}

string GetFileName (string path) {
	auto p = fs::path(path);
	return p.stem();
}