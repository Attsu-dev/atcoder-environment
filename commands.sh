alias g='g++ -std=c++23 -I ~/atcoder/ac-library -g -Wall -Wextra -Wshadow -fsanitize=address,undefined'

function n() {
    cd /home/attsu/atcoder/workspace || return
    cp /home/attsu/atcoder/library/template.cpp main.cpp
    rm -r test 2>/dev/null

    echo "$1" > .problem_url

    oj d "$1"
    code --goto main.cpp:6:3
}

function open-problem() {
    xdg-open "$(cat .problem_url)"
}

function t() {
    cat main.cpp | iconv -t sjis | clip.exe
    g main.cpp || return
    oj t
}

function atcoder-start() {
    acc n "$1"
    cd "$1/a/" || return
    code --goto main.cpp:6:3
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