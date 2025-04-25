import subprocess

print("This is the server.")

while True:

    DH_server = subprocess.run(["./DH_server.exe"], capture_output=True, text=True)
    DH_server_output = DH_server.stdout
    print(DH_server_output)
    shared_key = DH_server_output.split()[7]
    print("Shared key is", shared_key)