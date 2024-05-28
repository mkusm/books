import subprocess

# Define the command and arguments
commands = [str(n) for n in range(199999)]
command = ["./ex13", *commands]

# Run the command
result = subprocess.run(command, capture_output=True, text=True)

# Print the output
print("Output:", result.stdout)
print("Error:", result.stderr)
print("Return Code:", result.returncode)
