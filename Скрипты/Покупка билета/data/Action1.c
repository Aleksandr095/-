Action1()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128742.879546375zzcccVVpizzzzzzHDQHDDpcHVc", ENDITEM, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=54", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t69.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("SRCHUID=V=2&GUID=422240F17A5F4911A6BB8CC46069374E&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200510; DOMAIN=iecvlist.microsoft.com");

	web_add_auto_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t70.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("SRCHUID=V=2&GUID=422240F17A5F4911A6BB8CC46069374E&dmnchg=1; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200510; DOMAIN=c.urs.microsoft.com");

	web_url("l1.dat", 
		"URL=https://c.urs.microsoft.com/l1.dat?cw=637194112741176080&v=3&cv=9.11.18362.0&os=10.0.18363.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t71.inf", 
		LAST);

	web_revert_auto_header("UA-CPU");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=London", ENDITEM, 
		"Name=departDate", "Value=05/14/2020", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
		"Name=returnDate", "Value=05/15/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=43", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		LAST);

	return 0;
}