alias g='g++ -std=c++23 -I ~/atcoder/ac-library -g -Wall -Wextra -Wshadow -fsanitize=address,undefined'

function atcoder-start() {
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

function save-lib() {
    local lib_path="/home/attsu/atcoder/library"
    local snippet_dest="/mnt/c/Users/atsus/AppData/Roaming/Code/User/snippets/cpp.json"

    cp "$lib_path/snippets.json" "$snippet_dest"

    pushd "$lib_path" > /dev/null || return 1

    git add .
    git commit -m "update"
    git push origin main

    popd > /dev/null
}