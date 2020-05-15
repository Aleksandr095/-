Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(14);

	lr_start_transaction("Просмотр квитанций");

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=Aleksandr095", ENDITEM, 
		"Name=password", "Value=19741995", ENDITEM, 
		"Name=login.x", "Value=74", ENDITEM, 
		"Name=login.y", "Value=12", ENDITEM, 
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("Просмотр квитанций",LR_AUTO);

	return 0;
}