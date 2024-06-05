# python3 script

import subprocess

def test(command="./ex17"):
    string = "very_long_string_" * 100
    print(f"command: {command} tmp.db c")
    subprocess.run([f"{command}", "tmp.db", "c"])
    print(f"command: {command} tmp.db s 1 <long string> test@test.com")
    subprocess.run([f"{command}", "tmp.db", "s", "1", string, "test@test.com"])
    print(f"command: {command} tmp.db g 1")
    subprocess.run([f"{command}", "tmp.db", "g", "1"])
    print(f"command: {command} tmp.db d 1")
    subprocess.run([f"{command}", "tmp.db", "d", "1"])
    print(f"command: {command} tmp.db g 1")
    subprocess.run([f"{command}", "tmp.db", "g", "1"])


if __name__ == "__main__":
    from sys import argv
    test(argv[1])
