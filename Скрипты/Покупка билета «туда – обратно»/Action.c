Action()
{

/*Correlation comment - Do not change!  Original value='128762.222924261zzcDcAzpitVzzzzHDQHDQpctVAf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

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

	lr_start_transaction("Вход");

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

	lr_think_time(5);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t12.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=67", ENDITEM,
		"Name=login.y", "Value=2", ENDITEM,
		LAST);

	lr_end_transaction("Вход",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Переход на страницу Flight");
	
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

	lr_end_transaction("Переход на страницу Flight",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Заполнение полей");
	

	web_reg_find("Search=Body",
		"Text=Flight Selections",
		LAST);

	web_reg_save_param_ex(
		"ParamName=outboundFlight",
		"LB=\"outboundFlight\" value\=\"",
		"RB=\"",
		"NotFound=warning",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=returnFlight",
		"LB=\"returnFlight\" value\=\"",
		"RB=\"",
		"NotFound=warning",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		LAST);

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
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=41", ENDITEM, 
		"Name=findFlights.y", "Value=15", ENDITEM, 
		LAST);

	lr_end_transaction("Заполнение полей",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Выбор рейса");

	web_reg_find("Search=Body",
		"Text=Flight Reservation",
		LAST);
	
	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight_1}", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight_1}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=38", ENDITEM, 
		"Name=reserveFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("Выбор рейса",LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("Оплата");

	web_reg_find("Search=Body",
		"Text=Reservation Made!",
		LAST);

	
	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={login}", ENDITEM, 
		"Name=lastName", "Value={login}", ENDITEM, 
		"Name=address1", "Value=&#1050;&#1072;&#1083;&#1080;&#1085;&#1080;&#1085;&#1072; 36", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value={login} {login}", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=05/25", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight_1}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight_1}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=34", ENDITEM, 
		"Name=buyFlights.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("Оплата", LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Переход на страницу Itinerary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Переход на страницу Itinerary",LR_AUTO);

	lr_end_transaction("4_Покупка билета туда - обратно",LR_AUTO);

	return 0;
}