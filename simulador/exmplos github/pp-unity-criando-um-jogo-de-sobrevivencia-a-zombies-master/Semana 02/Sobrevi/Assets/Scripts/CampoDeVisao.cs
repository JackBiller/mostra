﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CampoDeVisao : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    private void OnTriggerEnter(Collider other){
        if (other.gameObject.CompareTag("Player")){
            transform.parent.gameObject.GetComponent<Zombie>().deveSeguir = true;
        }
    }

    private void OnTriggerExit(Collider other){
        if (other.gameObject.CompareTag("Player")){
            transform.parent.gameObject.GetComponent<Zombie>().deveSeguir = false;
        }
    }
}
