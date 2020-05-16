Action()
{
	int random, flightID_count, i;
	
		
	
/*Correlation comment - Do not change!  Original value='128756.919319563zzccQDtpADHfDQHDHpzAtccf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("2_Отмена всех броней");
	
	lr_start_transaction("Вход");
	
	web_reg_find("Search=Body",
		"Text=User password was correct ",
		LAST);	
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t33.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=65", ENDITEM,
		"Name=login.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("Вход", LR_AUTO);
	
	lr_start_transaction("Переход на страницу Iternarary");
	
	web_reg_save_param_ex(
		"ParamName=c_flightids",
	    "LB=<input type=\"hidden\" name\=\"flightID\" value\=\"",
	    "RB=\"",
	    "NotFound=warning",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		LAST);
    
	
	web_reg_save_param_ex(
		"ParamName=c_cgifields",
	    "lb=<input type=\"hidden\" name\=\".cgifields\" value\=\"",
	    "rb=\"",
	    "NotFound=warning",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		LAST);
	
	web_reg_find("Search=Body",
		"Text=Web Tours",
		LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Переход на страницу Iternarary", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("Отмена бронирования");


	flightID_count =  atoi(lr_eval_string("{c_flightids_count}"));
	random = rand() % (flightID_count - 1) + 1;
	
	lr_save_int(random, "random");
	

    lr_param_sprintf("c_buffer","%s=on&", lr_eval_string("{random}"));
 
    
	

	for (i=1;i<=flightID_count;i++)
    {
	   lr_param_sprintf("c_buffer",
        "%sflightID=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("c_flightids",
        i));

        lr_param_sprintf("c_buffer",
        "%s.cgifields=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("c_cgifields",
        i));	
	}
	
	

	lr_save_string(lr_eval_string("{c_buffer}removeFlights.x=36&removeFlights.y=4"), "c_wcr");
	
	// check
	//    lr_save_string(lr_eval_string(lr_eval_string("{c_flightids_{random}}")), "c_cancelflight");
	
	//    web_reg_find("Text={c_cancelflight}", LAST);

	
	web_custom_request("itinerary.pl",
	    "URL=http://localhost:1080/WebTours/itinerary.pl",
	    "Method=POST",
	    "Resource=0",
	    "RecContentType=text/html",
	    "Referer=http://localhost:1080/WebTours/itinerary.pl",
	    "Snapshot=t23.inf",
	    "Mode=HTTP",
	    "Body={c_wcr}",
	    LAST);
	
	lr_end_transaction("Отмена бронирования", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("Выход");
	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
	
	lr_end_transaction("Выход", LR_AUTO);
	
	lr_end_transaction("2_Отмена всех броней", LR_AUTO);
}