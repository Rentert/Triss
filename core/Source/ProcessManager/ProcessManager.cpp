//
// Created by Aleksandrov Oleg
//

#include "../../Headers/ProcessManager/ProcessManager.h"
#include <signal.h>
#include <iostream>

bool ProcessManager::killByPid(int pid) {
    return kill(pid, SIGTERM) == 0;
}
