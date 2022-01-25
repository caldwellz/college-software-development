#Program: 13
#Names: Jackson Oh, Zach Caldwell
#Date: April 4, 2017
#Instructor: Jeff Light
#Description: Using BeautifulSoup

import requests, bs4

def main(): #main function needed in all programs for automated testing
	print("Screen Scraping 'http://deseretnews.com'")
	print()

	baseURL = 'http://deseretnews.com'
	outFile = open('DeseretNewsHeadlines.txt', 'w')
	res = requests.get(baseURL)

	print("Loading the online page 'http://www.deseretnews.com' into the dnWeb BeautifulSoup object...")
	dnWeb = bs4.BeautifulSoup(res.text, "html.parser")

	print("Getting the elements from the dnWeb BeautifulSoup object.")
	elements = dnWeb.find_all('a',class_='rotator-item__story-headline')
	for elem_num in range(0, len(elements)):
		article_title= elements[elem_num].text
		article_url= baseURL+elements[elem_num]['href']

		print("Element " + str(elem_num) + "'s text value is: " + article_title)
		print("Element " + str(elem_num) + "'s href is: " + article_url)
		outFile.write(article_title + ": " + article_url + '\n')
		elem_num= elem_num+1

	outFile.close()
	print()
	print('The data has been written to the DeseretNewsHeadlines.txt file')


if __name__ == '__main__':
    main()  #execute main function
