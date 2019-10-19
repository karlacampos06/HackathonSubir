package com.example.presidente.controllers;

import java.io.IOException;
import java.util.Map;

import com.example.presidente.ReadCSV;
import com.example.presidente.entity.Presidente;
import com.example.presidente.services.AwsRekognitionService;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

@RestController

public class EjemploController {


	private AwsRekognitionService awsRekognitionService;


	 public EjemploController(AwsRekognitionService awsRekognitionService) {
        this.awsRekognitionService = awsRekognitionService;
	}
	
	@PostMapping(value="/imagen/comparar", produces = {"application/json"})
    public  @ResponseBody String detectModerationLabels(@RequestParam(value  = "image") MultipartFile image) throws IOException {
	   
	   
		if(awsRekognitionService.detectModerationLabels(image)){
			//response.put("status", "identico");
			 return "{\"status\":correcto}";
		}
		else
		{
			return "{\"status\":diferente}";
		}
		
	   
    }

	@PostMapping(value = "/consultar", produces = { "application/json" })
	public @ResponseBody Presidente getPresidente(@RequestBody Map<String,String>data)throws IOException {
		ReadCSV leer=null;
		int id= Integer.parseInt(data.get("id"));
		//int id= 22987983;
		
		switch(id){
			case 22987983:
			leer = new ReadCSV("presidentes", "cuernavaca.csv");
			leer.readFile();
			System.out.println("llego peticion");
			
			break;
			case 23670212:
			leer = new ReadCSV("presidentes", "jiutepec.csv");
			System.out.println("llego peticion");
			leer.readFile();
			break;



		}
			return leer.getPresidenteInfo();


		

		


		/*presidente.setId(1);
		presidente.setNombre("carlos");*/
 
		
	}

}
