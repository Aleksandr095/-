Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("4_Покупка билета туда - обратно");

	lr_start_transaction("D[jl");

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
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(16);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128762.222924261zzcDcAzpitVzzzzHDQHDQpctVAf", ENDITEM, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=67", ENDITEM, 
		"Name=login.y", "Value=2", ENDITEM, 
		LAST);

	lr_end_transaction("D[jl",LR_AUTO);

	lr_think_time(4);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t14.inf", 
		LAST);

	lr_think_time(41);

	lr_start_transaction("Заполнение полей");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=05/16/2020", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
		"Name=returnDate", "Value=05/20/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=41", ENDITEM, 
		"Name=findFlights.y", "Value=15", ENDITEM, 
		LAST);

	lr_end_transaction("Заполнение полей",LR_AUTO);

	lr_think_time(12);

	lr_start_transaction("Выбор рейса");

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=040;508;05/16/2020", ENDITEM, 
		"Name=returnFlight", "Value=400;508;05/20/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=38", ENDITEM, 
		"Name=reserveFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("Выбор рейса",LR_AUTO);

	lr_think_time(22);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=user1", ENDITEM, 
		"Name=lastName", "Value=user1", ENDITEM, 
		"Name=address1", "Value=&#1050;&#1072;&#1083;&#1080;&#1085;&#1080;&#1085;&#1072; 36", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=user1 user1", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=05/25", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value=040;508;05/16/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=400;508;05/20/2020", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=34", ENDITEM, 
		"Name=buyFlights.y", "Value=14", ENDITEM, 
		LAST);

	lr_think_time(16);

	lr_start_transaction("Выход");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Выход",LR_AUTO);

	lr_end_transaction("4_Покупка билета туда - обратно",LR_AUTO);

	return 0;
}