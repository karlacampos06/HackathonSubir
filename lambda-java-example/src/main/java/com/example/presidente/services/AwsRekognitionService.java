package com.example.presidente.services;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.List;

import com.amazonaws.auth.AWSStaticCredentialsProvider;
import com.amazonaws.auth.BasicAWSCredentials;
import com.amazonaws.regions.Regions;
import com.amazonaws.services.rekognition.AmazonRekognition;
import com.amazonaws.services.rekognition.model.BoundingBox;
import com.amazonaws.services.rekognition.model.CompareFacesMatch;
import com.amazonaws.services.rekognition.model.CompareFacesRequest;
import com.amazonaws.services.rekognition.model.CompareFacesResult;
import com.amazonaws.services.rekognition.model.ComparedFace;
import com.amazonaws.services.rekognition.model.DetectModerationLabelsRequest;
import com.amazonaws.services.rekognition.model.Image;
import com.amazonaws.services.rekognition.model.S3Object;
import com.amazonaws.services.s3.AmazonS3;
import com.amazonaws.services.s3.AmazonS3ClientBuilder;
import com.example.presidente.entity.Presidente;

import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

@Service
public class AwsRekognitionService {

        int[] ids = { 22987983, 23670212 };

        private AmazonRekognition client;

        Regions clientRegion = Regions.US_EAST_2;

        public AwsRekognitionService(AmazonRekognition client) {
                this.client = client;
        }

        public /* DetectModerationLabelsResult */boolean detectModerationLabels(MultipartFile imageToCheck)
                        throws IOException {
                

                
                BasicAWSCredentials credentials = new BasicAWSCredentials("AKIAQ775TH3SJPKSUJL2",
                                "/SXU66pUqiyEt19ZxqemWQApq9joNnvK8hPvxio8");

                AmazonS3 s3Client = /* AmazonCloudFrontAsyncClientBuilder.standard() */AmazonS3ClientBuilder.standard()
                                .withRegion(clientRegion).withCredentials(new AWSStaticCredentialsProvider(credentials))
                                .build();

                System.out.println("Downloading an object");
           

                DetectModerationLabelsRequest request = new DetectModerationLabelsRequest()
                                .withImage(new Image().withBytes(ByteBuffer.wrap(imageToCheck.getBytes())));

              
                        
                                CompareFacesRequest r = new CompareFacesRequest()
                                                .withSourceImage(new Image()
                                                                .withBytes(ByteBuffer.wrap(imageToCheck.getBytes())))
                                                .withTargetImage(new Image().withS3Object(new S3Object()
                                                                .withName("villalobos.jpg").withBucket("presidentes")))
                                                .withSimilarityThreshold(80F);

                                CompareFacesResult result = client.compareFaces(r);

                                List<CompareFacesMatch> faceDetails = result.getFaceMatches();
                                for (CompareFacesMatch match : faceDetails) {
                                        ComparedFace face = match.getFace();
                                        BoundingBox position = face.getBoundingBox();
                                        
                                        return true;

                                }
                        

                

                return false;

        }

}
