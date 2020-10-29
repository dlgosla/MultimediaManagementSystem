#include "Event.h"

void Event::setRecord(string e_name, string desc, int count)
{
	eventName = e_name;
	description = desc;
	countOfEvent = count;
}
void Event::printRecord()
{
	eventList.DisplayRecord();
}

int Event::Add()
{
	EventType e;
	e.SetRecordFromKB();
	countOfEvent++;
	eventList.Add(e);
	return 1;
	
}
int Event::Delete()
{
	EventType e;
	e.SetNameFromKB();
	eventList.Delete(e);
	countOfEvent--;
	return 1;
}
int Event::Retrieve()
{
	EventType e;
	e.SetNameFromKB();
	return eventList.Retrieve_SeqS(e);
}