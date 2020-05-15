Action()
{
	int random, flightID_count;
	
	
	
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

	lr_think_time(4);

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

	web_reg_save_param_ex(
		"ParamName=flightID",
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
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(8);
	
	
	    //This code selects what itinerary to cancel.
    //In this case it is the last one that was just created

   // lr_param_sprintf("c_buffer","%s=on&", lr_eval_string("{c_cgifields_count}"));

    //This code builds the values for flight id and cgi fields

//    for (i=1;i<=atoi(lr_eval_string("{c_cgifields_count}"));i++)
//    {
//        lr_param_sprintf("c_buffer",
//        "%sflightID=%s&",
//        lr_eval_string("{c_buffer}"),
//        lr_paramarr_idx("c_cgifields",
//        i));
//
//        lr_param_sprintf("c_buffer",
//        "%s.cgifields=%s&",
//        lr_eval_string("{c_buffer}"),
//        lr_paramarr_idx("c_cgifields",
//        i));
//    }

flightID_count =  atoi(lr_eval_string("{flightID_count}"));
	random = rand() % (flightID_count - 1) + 1;
	
	lr_save_int(random, "random");
	
	lr_save_string(lr_paramarr_idx("flightID", random), "valFlightID");
	lr_save_string(lr_paramarr_idx("c_cgifields", random), "valC_cgifields");

	lr_output_message("%d", random);
	lr_output_message("%s", lr_paramarr_idx("flightID", random));
	
	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name={random}", "Value=on", ENDITEM, 
		
		"Name=flightID", "Value={valFlightID}", ENDITEM, 
		"Name=c_cgifields", "Value=valC_cgifields", ENDITEM,
		
		
		"Name=removeFlights.x", "Value=70", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		LAST);

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
}