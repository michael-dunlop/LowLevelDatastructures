#include "DLList.h"
#include "stdio.h"
/**
 * @brief      Constructor for the DLList.
 */
DLList::DLList()
{
	/** @todo Write a constructor for a dllist. Check slides! **/
	head = new DLNode();
	head->next = head;
	head->prev = head;
}

/**
 * @brief      Destructor for the DLList.
 */
DLList::~DLList()
{
	/** @todo Clean up your mess! **/
	DLNode * e = head->next;
	while(e != head){
		DLNode * next = e->next;
		delete e;
		e = next;
	}

	delete head;
}

/**
 * @brief      Print the DLList line by line.
 */
void DLList::print()
{
	/** @todo Print this list line by line **/
	DLNode * n = head->next;
	while(n != head){
		printf("%d\n", n->data);
		n = n->next;
	}
}

/**
 * @brief      Sort and print the list.
 * 
 * This function should sort and print the list.
 * Note: the actual list is NOT to be modified.
 * In other words, it should only *print* in a
 * sorted order, not actually sort the list.
 */
void DLList::printSorted()
{
	/** @todo Print a sorted copy of this list **/
	DLNode * n = head->next;
	int len = 0;
	while( n != head){
		len++;
		n = n->next;
	}

	n = head->next;

	int vals[len];

	for(int i = 0; i < len; i++){
		vals[i] = n->data;
		n = n->next;
	}

	for(int i = 0; i < len - 1; i++){
		for(int j = i + 1; j < len; j++){
			if(vals[i] > vals[j]){
				int dum = vals[i];
				vals[i] = vals[j];
				vals[j] = dum;
			}
		}
	}

	for(int i = 0; i < len; i++){
		printf("%d\n", vals[i]);
	}
}

/**
 * @brief      Add to the front of the list.
 *
 * @param[in]  data  Item to add to front.
 */
void DLList::insertFront(int data)
{
	/** @todo Insert to the front of the list **/
	DLNode * e = new DLNode();
	e->data = data;
	e->next = head->next;
	e->prev = head;
	head->next = e;
	e->next->prev = e;
}

/**
 * @brief      Removes & stores the last element.
 *
 * The last element is removed and stored in the
 * referenced variable data.
 * 
 * @param      data  Thing in which we are storing the data.
 *
 * @return     True upon successful removal.
 */
bool DLList::removeLast(int & data)
{
	/** @todo Remove the last thing **/
	DLNode * e = head->prev;
	head->prev = e->prev;
	e->prev->next = head;
	data = e->data;
	delete e;
	return true;
}
/**
 * @brief      Difference of two lists.
 *
 * @param      list  Subtrahend.
 *
 * @return     Returns a pointer to the difference.
 */
DLList * DLList::difference(DLList & list)
{
	DLList * diff = new DLList();
	/** @todo Implement this function **/
	DLNode * a = head->next;
	DLNode * b = list.head->next;

	while(a != head){
		while(b != list.head){
			if(b->data == a->data){
				break;
			}
			b = b->next;
		}
		if(b == list.head){
			diff->insertFront(a->data);
		}
		a = a->next;
		b = list.head->next;
	}
	return diff;
}

/**
 * @brief      Returns a sublist of items in a range.
 *
 * @param[in]  start  First index.
 * @param[in]  end    Second index.
 *
 * @return     Elements between first and second index.
 */
DLList * DLList::getRange(int start, int end)
{
	DLList * range = new DLList();
	/** @todo getRange **/
	DLNode * e = head->next;
	
	for(int i = 0; i < start; i++){
		e = e->next;
	}

	for(int i = 0; i < (end - start); i++){
		range->insertFront(e->data);
		e = e->next;
	}
	return range;
}

/**
 * @brief      Intersection of this list and another list.
 *
 * @param      list  The other list.
 *
 * @return     Elements list shares with this one.
 */
DLList * DLList::intersection(DLList & list)
{
	DLList * inter = new DLList();
	/** @todo intersection **/
	DLNode * e = head->next;
	DLNode * d = list.head->next;

	while(e != head){
		while(d != list.head){
			if(d->data == e->data){
				DLNode * n = new DLNode();
				n->data = d->data;
				n->prev = inter->head->prev;
				inter->head->prev->next = n;
				n->next = inter->head;
				inter->head->prev = n;
				
				break;
			}	
			d = d->next;
		}	
		d = list.head->next;
		e = e->next;
	}
	return  inter;
}

