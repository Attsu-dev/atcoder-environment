alias g='g++ -std=c++23 -I ~/atcoder/library -I ~/atcoder/ac-library -g -Wall -Wextra -fsanitize=address,undefined'

function n() {
    cd /home/attsu/atcoder/workspace || return
    cp /home/attsu/atcoder/library/template/main.cpp main.cpp
    rm -r test 2>/dev/null

    oj d "$1"
    code --goto main.cpp:4:3
}

function t() {
    oj-bundle -I ~/atcoder/library/ main.cpp > submit.cpp 2>/dev/null || return
    g submit.cpp || return
    oj t
    cat submit.cpp | iconv -t sjis | clip.exe
}

function atcoder-start() {
    acc n "$1"
    cd "$1/a/" || return
    code --goto main.cpp:4:3
}

function to() {
    cd "../$1/" || return
    code --goto main.cpp:4:3
}

function zip2test() {
    unzip "$HOME/downloads/samples-$1.zip" -d test || return
    rm "$HOME/downloads/samples-$1.zip"*
    for f in test/*.ans;do
        mv "$f" "${f%.ans}.out"
    done
}

function randomtest-init() {
    cp /home/attsu/atcoder/library/template/generate.py .
    cp main.cpp naive.cpp
}

function randomtest() {
    local tests="${1:-1000}"

    g main.cpp || return
    g naive.cpp -o naive || return

    for ((i = 0; i < tests; i++)); do
        python3 generate.py "$i" > input.txt || return

        ./a.out < input.txt > output.txt || return
        ./naive < input.txt > expected.txt || return

        if ! cmp -s expected.txt output.txt; then
            echo "[input]"
            cat input.txt
            echo "[output]"
            cat output.txt
            echo "[expected]"
            cat expected.txt
            return 1
        fi
    done

    echo "Accepted: $tests tests"
}

function expand-ac-library() {
    local file="${1:-submit.cpp}"
    python3 ~/atcoder/ac-library/expander.py --lib ~/atcoder/ac-library/ "$file"
    cat combined.cpp | iconv -t sjis | clip.exe
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
