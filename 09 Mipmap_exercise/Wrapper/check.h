#pragma once
#ifdef DEBUG
#define GL_CALL(FUNC) FUNC;checkError();
#else 
#define GL_CALL(FUNC) FUNC;
#endif


void checkError();