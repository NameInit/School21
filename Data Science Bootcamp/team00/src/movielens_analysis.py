from collections import Counter, defaultdict
from datetime import datetime
from bs4 import BeautifulSoup
import re, requests


class Ratings:
	def __init__(self, filename:str):
		self.filename:str=filename
		self.title:list[str] = None
		self.data:list[list[str]] = None

	def load_data(self) -> dict["title": list[str], "data": list[list[str]]]:
		try:
			with open(self.filename, 'r', encoding='utf-8', errors='ignore') as f:
				self.title = f.readline().strip().split(',')
				self.data = list()
				for line in f:
					self.data.append(line.strip().split(','))
					if len(self.data)==1000:
						break
			return {"title": self.title, "data": self.data}
		except Exception:
			raise Exception(f"Not found data: {self.filename}")

	def get_filename(self) -> str:
		return self.filename

	def set_filename(self, filename: str) -> None:
		self.filename=filename
		self.title = None
		self.data = None

	def clear(self) -> None:
		self.filename=None
		self.title=None
		self.data=None

	def get_col_on_name(self, name: str) -> list[str]:
		if self.data is None or self.title is None:
			return None
		index = self.title.index(name)
		return [item[index] for item in self.data]

	def mean_rating(self) -> float:
		summary: float = 0
		for item in self.data:
			summary+=float(item[2])
		return summary/len(self.data)
	
	def median_rating(self) -> float:
		max_rating: float = 0
		min_rating: float = -1
		for item in self.data:
			max_rating=max(max_rating, float(item[2]))
			min_rating = float(item[2]) if min_rating==-1 else min(min_rating, float(item[2]))
		return (max_rating-min_rating)/2 if min_rating!=-1 else None

	def top5_month(self) -> list[str]:
		cnt = Counter([datetime.fromtimestamp(int(item[3])).strftime('%B') for item in self.data])
		return [item[0] for item in cnt.most_common(5)]

	def create_dict_on_name_col(self, name_col) -> dict[str:dict[str:str]]:
		index = self.title.index(name_col)
		return {item[index]: {self.title[i]:item[i] for i in range(len(self.title)) if i!=index} for item in self.data}

	def id_best_films(self) -> list[str]:
		t_dict = defaultdict()
		for item in self.data:
			if item[1] in t_dict.keys():
				t_dict[item[1]]=[t_dict[item[1]][0]+1,t_dict[item[1]][1]+float(item[2])]
			else:
				t_dict[item[1]]=[1, float(item[2])]
		for key, value in t_dict.items():
			t_dict[key]=value[1]/value[0]

		
		return [item[0] for item in sorted([(key, value) for key, value in t_dict.items()], key=lambda x:x[1], reverse=True)]

class Tags:
	def __init__(self, filename:str):
		self.filename:str=filename
		self.title:list[str] = None
		self.data:list[list[str]] = None

	def load_data(self) -> dict["title": list[str], "data": list[list[str]]]:
		try:
			with open(self.filename, 'r', encoding='utf-8', errors='ignore') as f:
				self.title = f.readline().strip().split(',')
				self.data = list()
				for line in f:
					t_line=line.strip().split(',')
					self.data.append([t_line[0], t_line[1], ','.join(t_line[2:len(t_line)-1]), t_line[-1]])
					if len(self.data)==1000:
						break
			return {"title": self.title, "data": self.data}
		except Exception:
			raise Exception(f"Not found data: {self.filename}")
	
	def get_filename(self) -> str:
		return self.filename

	def set_filename(self, filename: str) -> None:
		self.filename=filename
		self.title = None
		self.data = None

	def clear(self) -> None:
		self.filename=None
		self.title=None
		self.data=None

	def get_col_on_name(self, name: str) -> list[str]:
		if self.data is None or self.title is None:
			return None
		index = self.title.index(name)
		return [item[index] for item in self.data]

	def longest_tag(self) -> str:
		l_tag: str = ""
		for item in self.data:
			if len(item[2])>len(l_tag):
				l_tag=item[2]
		return l_tag if len(l_tag)!=0 else None
	
	def top10_user_with_most_tag(self) -> list[str]:
		return [pair[0] for pair in Counter([item[0] for item in self.data]).most_common(10)]

	def create_dict_on_name_col(self, name_col) -> dict[str:dict[str:str]]:
		index = self.title.index(name_col)
		return {item[index]: {self.title[i]:item[i] for i in range(len(self.title)) if i!=index} for item in self.data}

class Movies:
	def __init__(self, filename:str):
		self.filename:str=filename
		self.title:list[str] = None
		self.data:list[list[str]] = None

	def load_data(self) -> dict["title": list[str], "data": list[list[str]]]:
		try:
			with open(self.filename, 'r', encoding='utf-8', errors='ignore') as f:
				self.title = f.readline().strip().split(',')
				self.data = list()
				for line in f:
					t_line=line.strip().split(',')
					self.data.append([t_line[0], ','.join(t_line[1:len(t_line)-1]), t_line[-1]])
					if len(self.data)==1000:
						break
			return {"title": self.title, "data": self.data}
		except Exception:
			raise Exception(f"Not found data: {self.filename}")
		
	def get_filename(self) -> str:
		return self.filename

	def set_filename(self, filename: str) -> None:
		self.filename=filename
		self.title = None
		self.data = None

	def clear(self) -> None:
		self.filename=None
		self.title=None
		self.data=None
	
	def get_col_on_name(self, name: str) -> list[str]:
		if self.data is None or self.title is None:
			return None
		index = self.title.index(name)
		return [item[index] for item in self.data]

	def year_most_films(self) -> str:
		pattern = r'.*\(([0-9]{4})\).*$'
		return Counter([re.search(pattern,item[1]).group(1) for item in self.data if re.search(pattern,item[1]) is not None]).most_common(1)[0][0]

	def create_dict_on_name_col(self, name_col) -> dict[str:dict[str:str]]:
		index = self.title.index(name_col)
		return {item[index]: {self.title[i]:item[i] for i in range(len(self.title)) if i!=index} for item in self.data}

class Links:
	def __init__(self, filename:str):
		self.filename:str=filename
		self.title:list[str] = None
		self.data:list[list[str]] = None

	def load_data(self) -> dict["title": list[str], "data": list[list[str]]]:
		try:
			with open(self.filename, 'r', encoding='utf-8', errors='ignore') as f:
				self.title = f.readline().strip().split(',')
				self.data = list()
				for line in f:
					self.data.append(line.strip().split(','))
					if len(self.data)==1000:
						break
			return {"title": self.title, "data": self.data}
		except Exception:
			raise Exception(f"Not found data: {self.filename}")
	
	def get_filename(self) -> str:
		return self.filename

	def set_filename(self, filename: str) -> None:
		self.filename=filename
		self.title = None
		self.data = None

	def clear(self) -> None:
		self.filename=None
		self.title=None
		self.data=None

	def get_col_on_name(self, name: str) -> list[str]:
		if self.data is None or self.title is None:
			return None
		index = self.title.index(name)
		return [item[index] for item in self.data]

	def create_dict_on_name_col(self, name_col) -> dict[str:dict[str:str]]:
		index = self.title.index(name_col)
		return {item[index]: {self.title[i]:item[i] for i in range(len(self.title)) if i!=index} for item in self.data}

	def duration_first_films(self, n: int = None) -> list[str]:
		if n is None or n>len(self.data):
			n=len(self.data)
		result: list = []
		for i in range(n):
			res = re.search(r'.*\(([0-9]*) min\).*', Links.scrape_imdb_info_on_imdbId(self.data[i][1])['runtime'])
			result.append(res.group(1) if res else None)
		return result

	def compare_rating_with_imdb(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		index_on_movieId = ratings.create_dict_on_name_col('movieId')
		k = set(index_on_movieId.keys())
		for item in self.data:
			yield f"ID: {item[1]} | DB: {index_on_movieId[item[0]]['rating'] if item[0] in k else 'N/A'} | WEBSITE: {Links.scrape_imdb_info_on_imdbId(item[1])['rating']}"

	def compare_genres_with_imdb(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		index_on_movieId = movies.create_dict_on_name_col('movieId')
		k = set(index_on_movieId.keys())
		for item in self.data:
			yield f"ID: {item[1]} | DB: {index_on_movieId[item[0]]['genres'].replace(' ','').split('|') if item[0] in k else 'N/A'} | WEBSITE: {Links.scrape_imdb_info_on_imdbId(item[1])['genres']}"

	def create_mini_reports(self):
		for item in self.data:
			info = Links.scrape_imdb_info_on_imdbId(item[1])
			yield f"Название: \"{info['title']}\"\tВремя:{info['runtime']}\nО чём: {info['plot']}"

	@staticmethod
	def scrape_imdb_info_on_imdbId(id):
		url = f"https://www.imdb.com/title/tt{id}/"
		headers = {
        	'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
    	}

		try:
			response = requests.get(url, headers=headers, timeout=10)
			soup = BeautifulSoup(response.text, 'html.parser')
			return {
				'title': soup.find('h1').text if soup.find('h1') else 'N/A',
				'rating': soup.find('div', class_='sc-4dc495c1-0 fUqjJu').text[:6] if soup.find('div', class_='sc-4dc495c1-0 fUqjJu') else 'N/A',
				'genres': [genre.text for genre in soup.find_all('span', class_='ipc-chip__text')][:5],
				'cast': [actor.text for actor in soup.find_all('a', {'data-testid': 'title-cast-item__actor'})[:5]],
				'plot': soup.find('span', {'data-testid': 'plot-l'}).text if soup.find('span', {'data-testid': 'plot-l'}) else 'N/A',
				'runtime': soup.find('li', {'data-testid': 'title-techspec_runtime'}).find('div').text if soup.find('li', {'data-testid': 'title-techspec_runtime'}) else 'N/A'
			}
		except Exception:
			raise Exception('Error parsing')

class Test:
	def test_load_links(self):
		links = Links('data/links.csv').load_data()
		assert links is not None
		assert links['title'] is not None
		assert links['data'] is not None
		assert len(links['data'])<=1000
		assert links['title']==['movieId','imdbId','tmdbId']
		assert links['data'][0]==['1','0114709','862']
		assert links['data'][-1]==['1301','0049223','830']
	
	def test_load_movies(self):
		movies = Movies('data/movies.csv').load_data()
		assert movies is not None
		assert movies['title'] is not None
		assert movies['data'] is not None
		assert len(movies['data'])<=1000
		assert movies['title']==['movieId','title','genres']
		assert movies['data'][0]==['1','Toy Story (1995)','Adventure|Animation|Children|Comedy|Fantasy']
		assert movies['data'][-1]==['1301','Forbidden Planet (1956)','Drama|Sci-Fi']
	
	def test_load_ratings(self):
		ratings = Ratings('data/ratings.csv').load_data()
		assert ratings is not None
		assert ratings['title'] is not None
		assert ratings['data'] is not None
		assert len(ratings['data'])<=1000
		assert ratings['title']==['userId','movieId','rating','timestamp']
		assert ratings['data'][0]==['1','1','4.0','964982703']
		assert ratings['data'][-1]==['7','30816','2.0','1107127004']
	
	def test_load_tags(self):
		tags = Tags('data/tags.csv').load_data()
		assert tags is not None
		assert tags['title'] is not None
		assert tags['data'] is not None
		assert len(tags['data'])<=1000
		assert tags['title']==['userId','movieId','tag','timestamp']
		assert tags['data'][0]==['2','60756','funny','1445714994']
		assert tags['data'][-1]==['474','31','high school','1137375502']
	
	def test_mean_rating(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.mean_rating()==3.669
	
	def test_median_rating(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.median_rating()==2.25
	
	def test_top5_month(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.top5_month()==['October', 'July', 'January', 'December', 'April']

	def test_longest_tag(self):
		tags=Tags('data/tags.csv')
		tags.load_data()
		assert tags.longest_tag() == 'Something for everyone in this one... saw it without and plan on seeing it with kids!'
	
	def test_top10_user_with_most_tag(self):
		tags=Tags('data/tags.csv')
		tags.load_data()
		assert tags.top10_user_with_most_tag()==['62', '424', '125', '357', '318', '184', '193', '474', '18', '119']
	
	def test_year_most_films(self):
		movies=Movies('data/movies.csv')
		movies.load_data()
		assert movies.year_most_films() == '1995'
	
	def test_create_dict_on_name_col_1(self):
		links = Links("data/links.csv")
		links.load_data()
		assert list(links.create_dict_on_name_col('movieId').items())[0] == ('1', {'imdbId': '0114709', 'tmdbId': '862'})


	def test_create_dict_on_name_col_2(self):
		movies = Movies("data/movies.csv")
		movies.load_data()
		assert list(movies.create_dict_on_name_col('movieId').items())[0] == ('1', {'genres': 'Adventure|Animation|Children|Comedy|Fantasy', 'title': 'Toy Story (1995)'})


	def test_create_dict_on_name_col_3(self):
		ratings = Ratings("data/ratings.csv")
		ratings.load_data()
		assert list(ratings.create_dict_on_name_col('movieId').items())[0] == ('1', {'rating': '4.5', 'timestamp': '1106635946', 'userId': '7'})


	def test_create_dict_on_name_col_4(self):
		tags = Tags("data/tags.csv")
		tags.load_data()
		assert list(tags.create_dict_on_name_col('movieId').items())[0] == ('60756', {'tag': 'will ferrell', 'timestamp': '1457846129', 'userId': '424'})
	
	def test_id_best_films(self):
		ratings = Ratings("data/ratings.csv")
		ratings.load_data()
		assert ratings.id_best_films()[:10]==['101','157','260','661','919','923','940','954','1023','1024']
	
	def test_scrape_imdb_info_on_imdbId(self):
		assert Links.scrape_imdb_info_on_imdbId('0114709') == {'cast': ['Tom Hanks',
						'Tim Allen',
						'Don Rickles',
						'Jim Varney',
						'Wallace Shawn'],
				'genres': ['Buddy Comedy',
							'Computer Animation',
							'Supernatural Fantasy',
							'Urban Adventure',
							'Adventure'],
				'plot': 'A cowboy doll is profoundly jealous when a new spaceman action '
						"figure supplants him as the top toy in a boy's bedroom. When "
						'circumstances separate them from their owner, the duo have to put '
						'aside their differences to return to him.',
				'rating': '8.3/10',
				'runtime': '1h 21m(81 min)',
				'title': 'История игрушек'}
	
	def test_duration_first_films(self):
		links = Links("data/links.csv")
		links.load_data()
		assert links.duration_first_films(5)==['81', '104', '101', '124', '106']
	
	def test_compare_rating_with_imdb(self):
		links = Links("data/links.csv")
		links.load_data()
		assert next(links.compare_rating_with_imdb())=='ID: 0114709 | DB: 4.5 | WEBSITE: 8.3/10'
	
	def test_compare_genres_with_imdb(self):
		links = Links("data/links.csv")
		links.load_data()
		assert next(links.compare_genres_with_imdb()) == 'ID: 0114709 | DB: [\'Adventure\', \'Animation\', \'Children\', \'Comedy\', \'Fantasy\'] | WEBSITE: [\'Buddy Comedy\', \'Computer Animation\', \'Supernatural Fantasy\', \'Urban Adventure\', \'Adventure\']'

	def test_create_mini_reports(self):
		links = Links("data/links.csv")
		links.load_data()
		assert next(links.create_mini_reports()) == 'Название: "История игрушек"\tВремя:1h 21m(81 min)\nО чём: A cowboy doll is profoundly jealous when a new spaceman action figure supplants him as the top toy in a boy\'s bedroom. When circumstances separate them from their owner, the duo have to put aside their differences to return to him.'
	
	def test_get_filename_links(self):
		links = Links('data/links.csv')
		links.load_data()
		assert links.get_filename() == 'data/links.csv'

	def test_get_filename_movies(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		assert movies.get_filename() == 'data/movies.csv'

	def test_get_filename_ratings(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.get_filename() == 'data/ratings.csv'

	def test_get_filename_tags(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		assert tags.get_filename() == 'data/tags.csv'

	def test_set_filename_links(self):
		links = Links('data/links.csv')
		links.load_data()
		links.set_filename("123")
		assert links.filename == "123"
		assert links.data is None
		assert links.title is None

	def test_set_filename_movies(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		movies.set_filename("123")
		assert movies.filename == "123"
		assert movies.data is None
		assert movies.title is None

	def test_set_filename_ratings(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		ratings.set_filename("123")
		assert ratings.filename == "123"
		assert ratings.data is None
		assert ratings.title is None

	def test_set_filename_tags(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		tags.set_filename("123")
		assert tags.filename == "123"
		assert tags.data is None
		assert tags.title is None

	def test_clear_links(self):
		links = Links('data/links.csv')
		links.load_data()
		links.clear()
		assert links.filename is None
		assert links.data is None
		assert links.title is None

	def test_clear_movies(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		movies.clear()
		assert movies.filename is None
		assert movies.data is None
		assert movies.title is None

	def test_clear_ratings(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		ratings.clear()
		assert ratings.filename is None
		assert ratings.data is None
		assert ratings.title is None

	def test_clear_tags(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		tags.clear()
		assert tags.filename is None
		assert tags.data is None
		assert tags.title is None

	def test_get_col_on_name_links1(self):
		links = Links('data/links.csv')
		links.load_data()
		assert links.get_col_on_name('movieId')[0] == '1'
		assert links.get_col_on_name('movieId')[-1] == '1301'
	
	def test_get_col_on_name_links2(self):
		links = Links('data/links.csv')
		links.load_data()
		assert links.get_col_on_name('imdbId')[0] == '0114709'
		assert links.get_col_on_name('imdbId')[-1] == '0049223'
	
	def test_get_col_on_name_links3(self):
		links = Links('data/links.csv')
		links.load_data()
		assert links.get_col_on_name('tmdbId')[0] == '862'
		assert links.get_col_on_name('tmdbId')[-1] == '830'
	
	def test_get_col_on_name_movies1(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		assert movies.get_col_on_name('movieId')[0] == '1'
		assert movies.get_col_on_name('movieId')[-1] == '1301'
	
	def test_get_col_on_name_movies2(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		assert movies.get_col_on_name('title')[0] == 'Toy Story (1995)'
		assert movies.get_col_on_name('title')[-1] == 'Forbidden Planet (1956)'
	
	def test_get_col_on_name_movies3(self):
		movies = Movies('data/movies.csv')
		movies.load_data()
		assert movies.get_col_on_name('genres')[0] == 'Adventure|Animation|Children|Comedy|Fantasy'
		assert movies.get_col_on_name('genres')[-1] == 'Drama|Sci-Fi'
	
	def test_get_col_on_name_ratings1(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.get_col_on_name('userId')[0] == '1'
		assert ratings.get_col_on_name('userId')[-1] == '7'
	
	def test_get_col_on_name_ratings2(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.get_col_on_name('movieId')[0] == '1'
		assert ratings.get_col_on_name('movieId')[-1] == '30816'
	
	def test_get_col_on_name_ratings3(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.get_col_on_name('rating')[0] == '4.0'
		assert ratings.get_col_on_name('rating')[-1] == '2.0'
	
	def test_get_col_on_name_ratings4(self):
		ratings = Ratings('data/ratings.csv')
		ratings.load_data()
		assert ratings.get_col_on_name('timestamp')[0] == '964982703'
		assert ratings.get_col_on_name('timestamp')[-1] == '1107127004'
	
	def test_get_col_on_name_tags1(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		assert tags.get_col_on_name('userId')[0] == '2'
		assert tags.get_col_on_name('userId')[-1] == '474'
	
	def test_get_col_on_name_tags2(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		assert tags.get_col_on_name('movieId')[0] == '60756'
		assert tags.get_col_on_name('movieId')[-1] == '31'
	
	def test_get_col_on_name_tags3(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		assert tags.get_col_on_name('tag')[0] == 'funny'
		assert tags.get_col_on_name('tag')[-1] == 'high school'
	
	def test_get_col_on_name_tags4(self):
		tags = Tags('data/tags.csv')
		tags.load_data()
		assert tags.get_col_on_name('timestamp')[0] == '1445714994'
		assert tags.get_col_on_name('timestamp')[-1] == '1137375502'