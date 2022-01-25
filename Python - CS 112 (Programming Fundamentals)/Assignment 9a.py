#Program: 9a
#Names: Svetlana Solovaya, Zach Caldwell
#Date: March 7, 2017
#Instructor: Jeff Light
#Description: Simple shopping list function.

def main(): #main function need in all programs for automated testing

	validMenuChoices = ['1','2','3','4','5']
	shoppingList = []  #Initialize the Shopping List

	#Loop to present the menu to the user and get their input.
	while True:
		print()
		print("1. Add Items")
		print("2. Delete Items")
		print("3. Show Items")
		print("4. Sort Items")
		print("5. Exit")
		print('Please enter a command: ',end='')
		cmd = get_choice(validMenuChoices)

		if cmd == '1':
			items1=add_items(shoppingList)
			print (items1,'items have been added to your Shopping List.')
		elif cmd == '2':
			items2=delete_items(shoppingList)
			print (items2,'items have been deleted from your Shopping List.')
		elif cmd == '3':
			show_items(shoppingList)
		elif cmd == '4':
			sort_items(shoppingList)
		else:
			break

#end of main() function


def add_items(list):
	new_item = ''
	items_added = 0
	while True:
		print()
		new_item = input("Add an item to the list (or just hit 'enter' when done): ").title()
		if new_item == '':
			break

		if new_item not in list:
			list.append(new_item)
			items_added = items_added + 1
			print('"' + new_item + '" has been added to the list.')
		else:
			print('"' + new_item + '" is already in the list.')

	return items_added

def delete_items(list):
	del_item = ''
	items_deleted = 0
	
	while True:
		print()
		del_item = input("Delete an item from the list(or just hit 'enter' when done): ").title()
		if del_item == '':
			break
		if del_item not in list:
			print ('"'+del_item+'"'+" is not an item in the list. Please try again.")
			show_items(list)
			continue

		list.remove(del_item)
		items_deleted = items_deleted+1
		print ('"'+ del_item+'"'+ "has been removed from the list")

	return items_deleted


def show_items(list):
	print()
	print ("List contains the following items")
	print (list)


def sort_items(list):
	list.sort()
	print()
	print("The list has been sorted.")
	show_items(list)


#Function get_choice() which only accepts input as designated from the validChoices list
###  DO NOT CHANGE THE CODE IN THE get_choice() FUNCTION  ###
def get_choice(validChoices):
	while True:
		userSelection = input()
		if userSelection in validChoices:
			return userSelection
		else:
			print('Invalid input.  Enter a choice from the menu: ', end = '')
#end of function get_choice()

if __name__ == '__main__':
	main()  #excucte main function
	
