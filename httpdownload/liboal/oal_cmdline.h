#ifndef _OAL_CMDLINE_H_
#define _OAL_CMDLINE_H_

#include "oal_type.h"

struct OAL_cliCommand {
	const char *name;
	const char *help;
	void(*function) (int argc, char **argv);
};
int OAL_cliStart();
int OAL_cliRegisterCommands(const struct OAL_cliCommand *commands, int num_commands);
int OAL_cliInit();

#endif


