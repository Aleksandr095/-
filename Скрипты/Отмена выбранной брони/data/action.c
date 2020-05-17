Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("SRCHUID=V=2&GUID=422240F17A5F4911A6BB8CC46069374E&dmnchg=1; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200510; DOMAIN=c.urs.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("l1.dat", 
		"URL=https://c.urs.microsoft.com/l1.dat?v=3&cv=9.11.18362.0&os=10.0.18363.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t38.inf", 
		LAST);

	lr_think_time(5);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128768.52345079zzcDfDApQcfDQHtVpVifff", ENDITEM, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=73", ENDITEM, 
		"Name=login.y", "Value=16", ENDITEM, 
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297802-819-uu", ENDITEM, 
		"Name=flightID", "Value=210302628-1612-uu", ENDITEM, 
		"Name=flightID", "Value=21030382-2333-uu", ENDITEM, 
		"Name=flightID", "Value=2103081523-30855-uu", ENDITEM, 
		"Name=flightID", "Value=210313356-3894-uu", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=60", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM, 
		LAST);

	return 0;
}