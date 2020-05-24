Action()
{

	
	lr_start_transaction("5_Просмотр квитанций");

	lr_start_transaction("Itinerary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);

	lr_think_time(5);

	

	lr_end_transaction("5_Просмотр квитанций",LR_AUTO);

	return 0;
}