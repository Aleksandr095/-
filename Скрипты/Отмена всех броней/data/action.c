Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(13);

	lr_start_transaction("2_Отмена всех броней");

	lr_start_transaction("Вход");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t62.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128763.714945322zzcDciDpfiHfDQHDQpHAVfcf", ENDITEM, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=71", ENDITEM, 
		"Name=login.y", "Value=12", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("Вход",LR_AUTO);

	web_add_cookie("SRCHUID=V=2&GUID=422240F17A5F4911A6BB8CC46069374E&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200510; DOMAIN=iecvlist.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t63.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(8);

	lr_start_transaction("Переход на страницу Iternarary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t64.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Переход на страницу Iternarary",LR_AUTO);

	lr_think_time(20);

	lr_start_transaction("Отмена бронирования");

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t65.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=210297049-795-uu", ENDITEM, 
		"Name=flightID", "Value=2103003-15-uu", ENDITEM, 
		"Name=flightID", "Value=2103044-23-uu", ENDITEM, 
		"Name=flightID", "Value=210309273-3105-uu", ENDITEM, 
		"Name=flightID", "Value=2103140839-38667-uu", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeAllFlights.x", "Value=42", ENDITEM, 
		"Name=removeAllFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("Отмена бронирования",LR_AUTO);

	lr_think_time(8);

	lr_start_transaction("Выход");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Выход",LR_AUTO);

	lr_end_transaction("2_Отмена всех броней",LR_AUTO);

	return 0;
}