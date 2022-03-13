#include "ThreadManager.h"
#include "Debugger.h"

thread_pool* ThreadManager::workers = DBG_NEW thread_pool();