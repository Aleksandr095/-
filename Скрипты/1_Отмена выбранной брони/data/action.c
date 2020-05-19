Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_start_transaction("1_Отмена выбранной брони");

	lr_start_transaction("login");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("l1.dat", 
		"URL=https://c.urs.microsoft.com/l1.dat?v=3&cv=9.11.18362.0&os=10.0.18363.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t48.inf", 
		LAST);

	lr_think_time(8);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128789.546375051zzctzVcpcQVzzzzHDQHtHpzHDHf", ENDITEM, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=47", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("suggestions.ru-RU", 
		"URL=https://ieonline.microsoft.com/iedomainsuggestions/ie11/suggestions.ru-RU", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t50.inf", 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(36);

	lr_start_transaction("Iterary");

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Iterary",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("Удаление брони");

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=2103066720-7803-uu", ENDITEM, 
		"Name=flightID", "Value=2103155594-15464-uu", ENDITEM, 
		"Name=flightID", "Value=210320033-2377-uu", ENDITEM, 
		"Name=flightID", "Value=210325955-3137-uu", ENDITEM, 
		"Name=flightID", "Value=21030014-3875-uu", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=48", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("Удаление брони",LR_AUTO);

	lr_think_time(9);

	lr_start_transaction("logout");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("1_Отмена выбранной брони",LR_AUTO);

	return 0;
}