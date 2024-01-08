// sampleshell.cpp: 定义应用程序的入口点。
//

#include "sampleshell.h"
extern const char* builtin_str[];
using namespace std;
std::vector<std::function<int(vector<string>)>> builtin_func = { ash_cd, ash_help, ash_exit };
int main()
{
	
	myShell();
	
	return PROCESSOR_EXIT;
}

void myShell()
{
	string line;
	vector<string> args;
	int status{ 0 };
	do {
		cout << ">";
		line = readLine();
		args = splitLine(line);
		status = shellExcute(args);
	} while (status);
}



std::string readLine()
{
	string line;
	std::getline(cin, line);
	if (cin.fail() || cin.bad()) {
		cerr << "error occupt during input" << std::endl;
		std::quick_exit(0);
	}
	if (cin.eof()) {
		cout << "end of file" << std::endl;
		std::quick_exit(1);
	}
	return line;
}

vector<string> splitLine(string input) {
	return splitString(input,' ');
}
int shellExcute(vector<string> args) {
	if (args[0].empty()) {
		return 1;
	}
	string commandline = vectorToString(args, " ");
	for (int i = 0; i < ash_num_builtins(); i++) {
		if (args[0]==string(builtin_str[i])) {
			return builtin_func[i](args);
		}
	}
	return shellLaunch((char*)commandline.c_str());

}
int shellLaunch(char* args) {
	
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi;

	// Command to execute
	LPCTSTR command = TEXT(args);

	// Create the new process
	if (!CreateProcess(NULL, const_cast<LPTSTR>(command), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		if (GetLastError() == 2) {
			std::cerr << "Failed to find command\n";
			return 1;
		}
		std::cerr << "Failed to create process. Error code: " << GetLastError() << std::endl;
		return 0;
	}

	// Wait for the process to exit
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 1;
}