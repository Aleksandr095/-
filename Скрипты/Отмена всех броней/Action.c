Action()
{

/*Correlation comment - Do not change!  Original value='128757.755771567zzccQHHpAzcfDQHDHpizcDHf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("2_Отмена всех рейсов");

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
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_start_transaction("Вход в систему");


	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t31.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=60", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("Вход в систему",LR_AUTO);

	lr_think_time(39);

	lr_start_transaction("Переход на страницу Itenerary");
	
	

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t32.inf", 
		LAST);

	lr_end_transaction("Переход на страницу Itenerary",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("Отмена всех рейсов");
	

	web_submit_form("itinerary.pl", 
		"Snapshot=t33.inf", 
		ITEMDATA, 
		"Name=removeAllFlights.x", "Value=31", ENDITEM, 
		"Name=removeAllFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("Отмена всех рейсов",LR_AUTO);

	lr_think_time(11);

	lr_start_transaction("Выход");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Ordinal=1", 
		"Snapshot=t34.inf", 
		LAST);

	lr_end_transaction("Выход",LR_AUTO);

	lr_end_transaction("2_Отмена всех рейсов",LR_AUTO);

	return 0;
}