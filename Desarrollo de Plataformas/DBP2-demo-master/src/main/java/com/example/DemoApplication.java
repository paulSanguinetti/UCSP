package com.example;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@SpringBootApplication
@EnableWebMvc
@Controller
public class DemoApplication {

	@RequestMapping(value = "/hello")
	@ResponseBody
	String hello(@RequestParam(required = false) String nombre) {
		if (nombre == null) {
			nombre = "Mundo";
		}
		return "Hola " + nombre;
	}

	@RequestMapping(value = "/process")
	void process(HttpServletRequest request, HttpServletResponse response) throws IOException {
		String operation = request.getParameter("operation");
		int a = Integer.parseInt(request.getParameter( "a"));
		int b = Integer.parseInt(request.getParameter( "b"));
		int c=0;
		if(operation.equals("sumar")){
			operation = " + ";
			c=a+b;			
		}else if(operation.equals("restar")){
			operation = " - ";
			c=a-b;			
		}else if(operation.equals("multi")){
			operation = " * ";
			c=a*b;			
		}else if(operation.equals("dividir")){
			operation = " / ";
			c=a/b;			
		}else{
			c=99999; 
		}
		
		response.setHeader("Content-Type", "text/html");
		response.setHeader("Cookies", "cookie; expires=2019/08/09");
		String html = "<html><i style='color: red'>"+ Integer.toString(a) + operation + Integer.toString(b) + " = " + Integer.toString(c) +"</i></html>";
		response.getOutputStream().println(html);
	}

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}
}
