import subprocess

print("This is the server.")

DH_server = subprocess.run(["go", "run", "DH_server/DH_server.go", "DH_server/server_main.go"], capture_output=True, text=True)

print(DH_server.stdout)