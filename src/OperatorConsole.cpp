#include "OperatorConsole.h"
#include <iostream>

using namespace std;

OperatorConsole::OperatorConsole() {
	// remains empty
}

OperatorConsole::~OperatorConsole() {
	// the history vector
	for(size_t i =0; i<history.size(); ++i){
		delete history[i];
	}
	history.clear();
}

bool OperatorConsole::executeCommand(Command* cmd) {
	if(!cmd) return false;
	cout<< "[OperatorConsole] Submitting command '"<< cmd->getName() << "' to execution pipeline.\n";
	bool success = cmd->execute();

	if(success){
		history.push_back(cmd);
	} else {
		cout<<"[OperatorConsole Error] Command '"<< cmd->getName() <<"' failed executioj.\n";
		delete cmd;
	}
	return success;
}

bool OperatorConsole::undoLastCommand() {
	if(history.empty()){
		cout<<"[OperatorConsole Error] Undo rejected: Command history stack is empty.\n";
		return false;
	}

	Command* lastCmd = history.back();
	history.pop_back();

	cout<<"[OperatorConsole] Reversing command '"<< lastCmd->getName() <<"'.\n";
	bool success = lastCmd->undo();
	delete lastCmd;
	return success;
}
