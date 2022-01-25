#Program: 10b
#Names: Svetlana Solovaya, Zach Caldwell
#Date: March 21, 2017
#Instructor: Jeff Light
#Description: Shopping List with Shelve

import shelve

def main(): #main function needed in all programs for automated testing
	validMenuChoices = ['1','2','3','4','5','6','7']
	shoppingList = []  #Initialize the Shopping List

	#Loop to present the menu to the user and get their input.

	shelfFile = shelve.open('ShoppingList')

	while True:
		print()
		print("1. Add Items")
		print("2. Delete Items")
		print("3. Show Items")
		print("4. Sort Items")
		print("5. Load List")
		print("6. Save List")
		print("7. Exit")
		print('Please enter a command: ',end='')
		cmd = get_choice(validMenuChoices)

		if cmd == '1':
			items1=add_items(shoppingList)
			print (items1,'items have been added to your Shopping List.')
		elif cmd == '2':
			items2=delete_items(shoppingList)
			print (items2,'items have been deleted from your Shopping List.')
		elif cmd == '3':
			show_items(shoppingList, 'Shopping List', 20, 6)
		elif cmd == '4':
			sort_items(shoppingList)
		elif cmd == '5':
			shoppingList = load_list(shelfFile, shoppingList)
		elif cmd == '6':
			save_list(shelfFile, shoppingList)
		else:
			break

	shelfFile.close()
#end of main() function


def load_list(shelfFile, list):
	if 'shopping_list' in shelfFile:
		newList = shelfFile['shopping_list']
		print ('List loaded')
		print ('')
		return newList
	else:
		print("Shopping List not found. Please save the list before trying to open it.")
		return list

def save_list(shelfFile, list):
	shelfFile['shopping_list'] = list
	print('List saved.')

def add_items(list):
	item_pair = []
	items_added = 0
	while True:
		print()
		new_item_input = input("Add an item to the list in the format <item:amount> (or just hit 'enter' when done): ").title()
		if new_item_input == '':
			break

		if ':' not in new_item_input:
			print("Invalid Entry. No ':' found. Entry must be in the form '<item> : <amount>'")
			continue

		item_pair = new_item_input.split(":")
		new_item = item_pair[0].strip()
		item_amount = item_pair[1].strip()
		if not item_amount.isdigit():
			print('"' + item_amount + '" is not a whole number. Please try again.')
			continue

		list_item = new_item + ':' + item_amount
		if list_item not in list:
			list.append(list_item)
			items_added = items_added + 1
			print('"' + list_item + '" has been added to the list.')
		else:
			print('"' + list_item + '" is already in the list.')

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
			show_items(list, 'Shopping List', 20, 6)
			continue

		list.remove(del_item)
		items_deleted = items_deleted+1
		print ('"'+ del_item+'"'+ "has been removed from the list")

	return items_deleted


def show_items(list, listTitle, leftWidth, rightWidth):
	print()
	print (listTitle.center(leftWidth + rightWidth, '-'))
	for item_string in list:
		item_pair = item_string.split(":")
		item = item_pair[0]
		item_amount = item_pair[1]
		print(item.ljust(leftWidth, '.') + item_amount.rjust(rightWidth))


def sort_items(list):
	list.sort()
	print()
	print("The list has been sorted.")
	show_items(list, 'Sorted Shopping List', 20, 6)


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
    main()  #execute main function
