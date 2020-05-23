Action()
{

	int random;
	
	web_reg_save_param("userSession",
	"LB/IC=name=\"userSession\" value=\"",
	"RB=\"/>",
	LAST);


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

	lr_start_transaction("Вход");

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

	lr_think_time(5);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t49.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
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

	lr_end_transaction("Вход",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Itinerary");
	
	web_reg_save_param_ex(
		"ParamName=flightID",
		"LB=\"flightID\" value\=\"",
		"RB=\"",
		"NotFound=warning",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		LAST);


	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Удаление брони");
	
	
	
	random = rand() % atoi(lr_eval_string("{flightID_count}")) + 1;
	lr_save_int(random, "random");

	
	web_submit_form("itinerary.pl", 
	    "Snapshot=t100.inf", 
	    ITEMDATA, 
	    "Name={random}", "Value=on", ENDITEM,  
	    "Name=removeFlights.x", "Value=60", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("Удаление брони",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Выход");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Выход",LR_AUTO);

	lr_end_transaction("1_Отмена выбранной брони",LR_AUTO);
	

	return 0;
}