import sys, subprocess, os

def check_venv():
	print(f"In venv: {os.getenv("VIRTUAL_ENV") is not None}")

def instalytor():
	subprocess.check_call([sys.executable, "-m", "pip", "install", "-r", "install.txt"])

def check_lib():
	result = subprocess.run([sys.executable, "-m", "pip", "freeze"], capture_output=True, text=True)
	with open("requirements.txt", 'w', encoding='utf-8') as f:
		f.write(result.stdout)

if __name__ == "__main__":
	try:
		check_venv()
		check_lib()
		instalytor()
		check_lib()
	except Exception:
		print("Unknown error")
		sys.exit(1)