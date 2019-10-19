package com.example.presidente;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import com.amazonaws.AmazonServiceException;
import com.amazonaws.SdkClientException;
import com.amazonaws.auth.AWSStaticCredentialsProvider;
import com.amazonaws.auth.BasicAWSCredentials;
import com.amazonaws.regions.Regions;
import com.amazonaws.services.s3.AmazonS3;
import com.amazonaws.services.s3.AmazonS3ClientBuilder;
import com.amazonaws.services.s3.model.GetObjectRequest;
import com.amazonaws.services.s3.model.S3Object;
import com.example.presidente.entity.Presidente;

public class ReadCSV{

 Regions clientRegion = Regions.US_EAST_2;
        String bucketName ;
        String key ;
        private List<String> lineas;

    public ReadCSV(String bucketName , String key){
        this.bucketName= bucketName;
        this.key= key;
        lineas= new ArrayList<>();
    }

       


        public void readFile() throws IOException {
                S3Object fullObject = null, objectPortion = null, headerOverrideObject = null;
                BasicAWSCredentials credentials= new BasicAWSCredentials("AKIAQ775TH3SJPKSUJL2", "/SXU66pUqiyEt19ZxqemWQApq9joNnvK8hPvxio8");
        try {
           AmazonS3 s3Client = /*AmazonCloudFrontAsyncClientBuilder.standard()*/AmazonS3ClientBuilder.standard()
                    .withRegion(clientRegion)
                    .withCredentials(new AWSStaticCredentialsProvider(credentials) )
                    .build();

            //AmazonS3 s3Client= new AmazonS3Client(credentials); 
            // Get an object and print its contents.
            System.out.println("Downloading an object");
            fullObject = s3Client.getObject(new GetObjectRequest(bucketName, key));
           // System.out.println("Content-Type: " + fullObject.getObjectMetadata().getContentType());
            //System.out.println("Content: ");
            displayTextInputStream(fullObject.getObjectContent());
/*bhjbfehjfbehbfehjfbehbfhefbef
            // Get a range of bytes from an object and print the bytes.
            GetObjectRequest rangeObjectRequest = new GetObjectRequest(bucketName, key)
                    .withRange(0, 9);
            objectPortion = s3Client.getObject(rangeObjectRequest);
           // System.out.println("Printing bytes retrieved.");
            displayTextInputStream(objectPortion.getObjectContent());

            // Get an entire object, overriding the specified response headers, and print the object's content.
            ResponseHeaderOverrides headerOverrides = new ResponseHeaderOverrides()
                    .withCacheControl("No-cache")
                    .withContentDisposition("attachment; filename=example.txt");
            GetObjectRequest getObjectRequestHeaderOverride = new GetObjectRequest(bucketName, key)
                    .withResponseHeaders(headerOverrides);
            headerOverrideObject = s3Client.getObject(getObjectRequestHeaderOverride);
            displayTextInputStream(headerOverrideObject.getObjectContent());*/
        } catch (AmazonServiceException e) {
            // The call was transmitted successfully, but Amazon S3 couldn't process 
            // it, so it returned an error response.
            e.printStackTrace();
        } catch (SdkClientException e) {
            // Amazon S3 couldn't be contacted for a response, or the client
            // couldn't parse the response from Amazon S3.
            e.printStackTrace();
        } finally {
            // To ensure that the network connection doesn't remain open, close any open input streams.
            if (fullObject != null) {
                fullObject.close();
            }
            if (objectPortion != null) {
                objectPortion.close();
            }
            if (headerOverrideObject != null) {
                headerOverrideObject.close();
            }
        }

        }

        private  void displayTextInputStream(InputStream input) throws IOException {
        // Read the text input stream one line at a time and display each line.
        //List<String> lineas= new ArrayList<>();
        BufferedReader reader = new BufferedReader(new InputStreamReader(input));
        String line = null;
        int i=0;
        while ((line = reader.readLine()) != null) {
           // System.out.println(line);
           //System.out.println(i++);
           lineas.add(line);
        }
       // System.out.println(lineas.size());
        //getPresidenteInfo(lineas);
    }


    public Presidente getPresidenteInfo(){
        Presidente presidente= new Presidente();
        String informacion= lineas.get(6);
        String[] datos = informacion.split(",");
        presidente.setId(Integer.parseInt(datos[0]));
        presidente.setCargo(datos[6]);
        presidente.setNombre(datos[9]);
        presidente.setApaterno(datos[10]);
        presidente.setAmaterno(datos[11]);
        presidente.setSueldo(Float.parseFloat(datos[15]));
        /*for (String linea : datos) {
            System.out.println(linea);
        }*/
        System.out.println("Nombre:" +presidente.getNombre());
        System.out.println("apaterno:" +presidente.getApaterno());
        System.out.println("amaterno:" +presidente.getAmaterno());
        System.out.println("cargo:" +presidente.getCargo());
        System.out.println("sueldo:" +presidente.getSueldo());

       // System.out.println(lineas.get(6));

        return presidente;
    }

        

        
}