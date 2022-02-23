
#include "Date.h"

Date::Date(){
	setDate(1901,1,1,0,1);
}

Date::Date(int y, int m, int d, int h, int dur){
	setDate(y,m,d,h,dur);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d, int h, int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(dur);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}

void Date::setHour(int h){
	if (h>23) hour = 23;
	else if (h<0) hour = 0;
	else hour = h;
}

void Date::setDuration(int dur){
	if (dur<1) duration=1;
	else if (dur>MAX_DURATION) duration = MAX_DURATION;
	else duration = dur;
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
int Date::getHour(){ return hour; }
const string& Date::getMonthName(){return months[month-1];}


//other

bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if(day == d.day){
				return hour < d.hour;
			}else{
				return day < d.day;
			}
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}	
}

void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()<<" "<<hour<<" "<<duration<<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

bool Date::overlaps(Date& d){
	if (year == d.year && month == d.month && day == d.day){
		//checking if the start time is in the range of the this reservation
		if(d.hour >= hour && d.hour < hour+duration) return true;
		//checking if the end time is in the range of the this reservation
		else if (d.hour + d.duration> hour && d.hour + d.duration <= hour+duration) return true;
		//checking if the start time is before the start of the this reservation and the end time is after the end time of this reservation
		else if (d.hour  <= hour && d.hour + d.duration >= hour+duration) return true;
		else return false;

	}
	else return false;
}
