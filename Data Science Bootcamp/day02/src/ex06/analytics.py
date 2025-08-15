import sys, logging, config, requests
from random import randint

logging.basicConfig(
    filename=config.log_file,
    level=logging.DEBUG,
    format="%(asctime)s %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S",
)

class Research:
	def __init__(self, filename):
		logging.info("Create researcher")
		self.filename=filename
	def file_reader(self,has_header:bool=True) -> list:
		logging.info("start file_reader")
		try:
			with open(self.filename, 'r', encoding='utf-8') as f:
				return list(map(lambda x: list(map(int,x.strip().replace(' ','').split(','))), f.readlines()[has_header:]))
		except Exception:
			print("Error args!!!")
			logging.error("error in file_reader")
			sys.exit(1)
		logging.info("end file_reader")
	def send_message(self, data):
		url = f"https://api.telegram.org/bot{config.token_bot}/sendMessage"
		json_config = {
			"chat_id": config.chat_id,
			"text": data,
			"parse_mode": "Markdown"
		}

		try:
			requests.post(url, json=json_config)
			logging.info("Сообще пришло!!!")
		except Exception:
			logging.error("Сообщение просрал!!!")
			exit(1)
	class Calculations:
		def __init__(self, data):
			logging.info("init calc")
			self.data = data

		def counts(self):
			logging.info("start counts")
			return [self.data.count(list(item)) for item in sorted(list(set(list(map(tuple, self.data)))), reverse=True)]

		def fractions(self):
			logging.info("start fractions")
			counts = [self.data.count(list(item)) for item in sorted(list(set(list(map(tuple, self.data)))), reverse=True)]
			return [count / sum(counts) * 100 for count in counts]
	class Analytics(Calculations):
		def predict_random(n):
			logging.info(f"start predict_random with {n}")
			return [[1,0] if randint(0,1) else [0,1] for _ in range(n)]

		def predict_last(data):
			logging.info("start predict_last")
			return data[-1]
		
		def save_file(data:str, name_of_file:str, r:str):
			logging.info("start save_file")
			with open(name_of_file+'.'+r, 'w') as f:
				f.write(data)