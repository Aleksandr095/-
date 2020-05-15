Action()
{

	
	lr_start_transaction("3_покупка билета");
	
/*Correlation comment - Do not change!  Original value='128736.295585257zzcViHDpcAtVzzzHDQHDVpcDQccf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("login");
	
	

	web_reg_find("Search=Body",
		"Text/IC=User password was correct",
		LAST);
	
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t54.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=62", ENDITEM,
		"Name=login.y", "Value=2", ENDITEM,
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("login",LR_AUTO);

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
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("go to Flight");

	web_reg_find("Search=Body",
		"Text/IC= User has returned to the search page",
		LAST);


	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t57.inf", 
		LAST);

	lr_end_transaction("go to Flight",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("insert to filds");
	
	web_reg_find("Search=Body",
		"Text/IC=Flight Selections",
		LAST);
	
	// отлов списка доступных рейсов

	// name="outboundFlight" value="
	
	web_reg_save_param_ex(
		"ParamName=outboundFlight",
		"LB=\"outboundFlight\" value\=\"",
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
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={TownDepart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={TownArrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=54", ENDITEM, 
		"Name=findFlights.y", "Value=4", ENDITEM, 
		LAST);

	
	
	lr_end_transaction("insert to filds",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("change flight");

	
	web_reg_find("Search=Body",
		"Text/IC=Flight Reservation",
		LAST);
	
	
	
	
	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t59.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight_1}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=66", ENDITEM,
		"Name=reserveFlights.y", "Value=10", ENDITEM,
		LAST);
	
	lr_end_transaction("change flight",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Payment");
	
	web_reg_find("Search=Body",
		"Text/IC=Reservation Made!",
		LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t60.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={login}", ENDITEM,
		"Name=lastName", "Value={login}", ENDITEM,
		"Name=address1", "Value=&#1050;&#1072;&#1083;&#1080;&#1085;&#1080;&#1085;&#1072; 36", ENDITEM,
		"Name=address2", "Value=", ENDITEM,
		"Name=pass1", "Value={login}  {login}", ENDITEM,
		"Name=creditCard", "Value=12345678", ENDITEM,
		"Name=expDate", "Value=", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight_1}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=75", ENDITEM,
		"Name=buyFlights.y", "Value=5", ENDITEM,
		LAST);

	lr_end_transaction("Payment",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("logout");

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("3_покупка билета",LR_AUTO);
	

	return 0;
}

