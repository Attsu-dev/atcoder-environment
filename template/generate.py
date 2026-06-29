import random
import sys


def main():
    seed = int(sys.argv[1]) if len(sys.argv) >= 2 else random.randrange(1 << 60)
    random.seed(seed)

    # TODO: 問題に合わせて入力生成を書く
    n = random.randint(1, 10)
    a = [random.randint(0, 20) for _ in range(n)]

    print(n)
    print(*a)


if __name__ == "__main__":
    main()
