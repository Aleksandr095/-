Action()
{


	
/*Correlation comment - Do not change!  Original value='128735.384447145zzcViczpDDHfDQHDApQfiAcf' Name ='userSession' Type ='ResponseBased'*/
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
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("SRCHUID=V=2&GUID=422240F17A5F4911A6BB8CC46069374E&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200510; DOMAIN=iecvlist.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("4_Покупка билета «туда – обратно»");

	lr_start_transaction("login");
	
	web_reg_find("Search=Body",
		"Text/IC=User password was correct",
		LAST);
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=59", ENDITEM,
		"Name=login.y", "Value=3", ENDITEM,
		LAST);
	
	lr_end_transaction("login",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Переход на страницу полеты");

	web_reg_find("Search=Body",
		"Text/IC= User has returned to the search page",
		LAST);
	
	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("Переход на страницу полеты",LR_AUTO);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t5.inf", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("Выбор рейса");
	
	web_reg_find("Search=Body",
		"Text/IC= Flight Selections",
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
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={return}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=48", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("Выбор рейса",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Выбор билета");

	web_reg_find("Search=Body",
		"Text/IC= Flight Reservation",
		LAST);
	
	web_submit_form("reservations.pl_2", 
		"Snapshot=t7.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight_1}", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight_1}", ENDITEM, 
		"Name=reserveFlights.x", "Value=49", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("Выбор билета",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Оплата");

	
	web_reg_find("Search=Body",
		"Text/IC= Reservation Made!",
		LAST);
	
	
	web_submit_form("reservations.pl_3", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=firstName", "Value={login}", ENDITEM, 
		"Name=lastName", "Value={pass}", ENDITEM, 
		"Name=address1", "Value=&#1050;&#1072;&#1083;&#1080;&#1085;&#1080;&#1085;&#1072; 36", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value={login} {login}", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=48", ENDITEM, 
		"Name=buyFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("Оплата",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Просмотр броней");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Просмотр броней",LR_AUTO);
	

	lr_end_transaction("4_Покупка билета «туда – обратно»",LR_AUTO);
	
	
	
	
	return 0;
}

