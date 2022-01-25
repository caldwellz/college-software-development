#Program: 12
#Names: Jackson Oh, Zach Caldwell
#Date: March 30, 2017
#Instructor: Jeff Light
#Description: Saving a web page

import requests

def validateURL(url):
	if not url.startswith("http://") and not url.startswith("https://"):
		url = "http://" + url

	try:
		res = requests.get(url)
		res.raise_for_status()
		return res
	except:
		return None


def saveURLFile(response, fn):
	if not fn.endswith('.html'):
		fn = fn + '.html'

	htmlFile = open(fn, 'wb')
	for chunk in response.iter_content(100000):
		htmlFile.write(chunk)

	htmlFile.close()
	return fn


def main(): #main function needed in all programs for automated testing
	print("This program will open a web page of your choice and save it to a file in the current directory.")

	while True:
		print()
		user_url = input("Please enter a URL: ")
		# Exit if the user enters nothing
		if user_url == '':
			return

		response = validateURL(user_url)
		if response == None:
			print("Invalid URL. Please try again.")
			continue
		else:
			fileName = input("Please enter a file name: ")
			saved_file = saveURLFile(response, fileName)
			print(saved_file, "has been saved.")


if __name__ == '__main__':
    main()  #execute main function
