alias g='g++ -std=c++23 -I ~/atcoder/ac-library'

function atcoder_start() {
    acc n "$1"
    cd "$1/a/" || return
    code --goto main.cpp:6:3
}

function t() {
    cat main.cpp | clip.exe
    g main.cpp || return
    oj t
}

function to() {
    cd "../$1/" || return
    code --goto main.cpp:6:3
}