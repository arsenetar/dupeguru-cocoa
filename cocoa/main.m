/* 
Copyright 2015 Hardcoded Software (http://www.hardcoded.net)

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import <Python.h>
#import <wchar.h>
#import <locale.h>

int main(int argc, char *argv[])
{
    /* We have to set the locate to UTF8 for mbstowcs() to correctly convert non-ascii chars in paths */
    setlocale(LC_ALL, "en_US.UTF-8");
    NSString *respath = [[NSBundle mainBundle] resourcePath];
    NSString *mainpy = [respath stringByAppendingPathComponent:@"dg_cocoa.py"];
    wchar_t wPythonPath[PATH_MAX+1];
    NSString *pypath = [respath stringByAppendingPathComponent:@"py"];
    mbstowcs(wPythonPath, [pypath fileSystemRepresentation], PATH_MAX+1);
    Py_SetPath(wPythonPath);
    Py_SetPythonHome(wPythonPath);
    Py_Initialize();
    PyGILState_STATE gilState = PyGILState_Ensure();
    FILE* fp = fopen([mainpy UTF8String], "r");
    int result = PyRun_SimpleFile(fp, [mainpy UTF8String]);
    if (result != 0) {
        return result;
    }
    fclose(fp);
    PyGILState_Release(gilState);
    if (gilState == PyGILState_LOCKED) {
        PyThreadState_Swap(NULL);
        PyEval_ReleaseLock();
    }
    result = NSApplicationMain(argc,  (const char **) argv);
    Py_Finalize();
    return result;
}
