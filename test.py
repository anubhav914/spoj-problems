from bs4 import BeautifulSoup
from urllib2 import urlopen
url = 'http://www.imdb.com/chart/top'

html = urlopen(url)
soup = BeautifulSoup(html)
titles = soup.find_all("td", class_="titleColumn")
names = [title.contents[3].text for title in titles]
print names