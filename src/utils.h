#ifndef UTILS_H
#define UTILS_H

#include <string>

using std::string;

#ifndef CWD_BUF_SIZE
#define CWD_BUF_SIZE 1024
#endif

namespace velocity::utils {
    string get_cwd();

    bool path_exists(string path);

    string file_contents(string file);

    int utf8_strlen(const string& str);

    string exec_stdout(const char* cmd);

    int exec_exit_code(const char* cmd);
} // namespace velocity::utils

#endif // UTILS_H
