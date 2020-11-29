#include "Event.h"

Event::~Event() {}

UnsortedList<EventType>  Event::getList()
{
	return contentsList;
}

int Event::getCountOfEvent()
{
	return countOfEvent;
}
void Event::replace(EventType item)
{
	contentsList.Replace(item);
}

bool Event::operator>(Event item)
{
	return (this->getEventName() > item.getEventName());
}	//return 1 if this.id > data.id, 0 if not.

// Compare two item types by item id.
bool Event::operator==(Event item)
{
	return (this->getEventName() == item.getEventName());
}

Event::Event() {
	//	contentsList = new string[MAXSIZE];
	eventName = "";
	description = "";
	countOfEvent = 0;
}

string  Event::getEventName() {
	return eventName;
}


void Event::setRecord(string e_name, string desc, int count)
{
	eventName = e_name;
	description = desc;
	countOfEvent = count;
}
void Event::printRecord(SortedList<ItemType>& master)
{

	contentsList.DisplayRecord(master);

}

int Event::Add(EventType e)
{
	contentsList.Add(e);
	countOfEvent++;
	return 1;

}
int Event::Delete(EventType e)
{
	contentsList.Delete(e);
	if (countOfEvent > 0)
		countOfEvent--;
	return 1;
}
int Event::Retrieve(EventType e)
{
	return contentsList.Retrieve(e);
}