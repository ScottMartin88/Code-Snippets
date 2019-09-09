using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Valve.VR;


public class PlayerMovement : MonoBehaviour
{
	GameObject tracker, forwardVector,d1,d2,Direction;
    bool engineOn = true;
    
    float throttle;
    float acceleration;
    [Header("Players Speed")]
    public float speed;   
    public float maxSpeed;

    [Header("Players Speed Modifiers")]
    [Range(500.0f, 1500.0f)]
    public float accelerationMultiplier = 1000.0f;
    [Range(100.0f, 500.0f)]
    public float maxSpeedMultiplier = 300;
    [Range(0.1f, 20.0f)]
    public float movementAdjuster = 1;

    float slowDown;
    float initialYAngle;
    float leanDistance;
    float leanAngle;

    [Header("Players Lean modifiers")]
    [Range(0.0f, 20.0f)]
    public float leanThreshhold = 0.5f;
    [Range(50.0f, 500.0f)]
    //public float leanAdjustment = 1.0f;


    float initialXAngle;
    float pitchDistance;
    float pitchAngle;


    public bool trigger;

    [Header("Players pitch modifiers")]
    [Range(0.0f, 20.0f)]
    public float pitchThreshhold = 0.5f;
    [Range(5.0f, 500.0f)]
    //public float pitchAdjustment = 1.0f;

    [Header("Players radius from spline")]
    public float radius = 90;

    float friction = 1.0f;

    public bool startSwitch;
    public bool bikeLevers  ;
    public bool leftFoot    ;
    public bool rightFoot   ;

    [Header("Debug Information")]
    public Vector3 xzoffset;
    public Vector3 yoffset, offset;
    [Space]
    public GameObject up;
    public GameObject down, left, right, empty, upDownController,leftRightController;

    float distUp, distDown, distLeft, distRight;

    [Space]
    public bool debugTestSpeed;
    AudioSource audioData;
    Vector3 directionNormalzized;

    SteamVR_TrackedObject trackedObject;

    Vector3 direction2;
    Vector3 forward;
    float direction2Length;
    Vector3 direction2Normalzized;
    bool directionSet = false;
    bool directionFix = false;

    float distance;

    int i = 0;

    void Start()
    {
        //THis is just going to set up the Game objects, looking for the names that are set in the prefab.
        tracker = transform.Find("tracker").gameObject;
        forwardVector = transform.Find("tracker/forwardVector").gameObject;
        audioData = GetComponent<AudioSource>();
        audioData.pitch = 0;
        throttle = Input.GetAxis("Throttle");
        Direction = transform.Find("Direction").gameObject;
        d1 = transform.Find("Direction/d1").gameObject;
        d2 = transform.Find("Direction/d2").gameObject;
        transform.localPosition += new Vector3(0, 0.01f, 0);
        up = transform.Find("tracker/up").gameObject;
        down = transform.Find("tracker/down").gameObject;
        left = transform.Find("tracker/left").gameObject;
        right = transform.Find("tracker/right").gameObject;
        

    }

    private void Update()
    {

        //this will see if the object is tracked yet, as the bike and everything will move when it does this will
        //then create the positions of the movement guiders and set up an initial distance between them and the controllers
        if (trackedObject == null)
        {
            trackedObject = tracker.GetComponent<SteamVR_TrackedObject>();
        }
        var device = SteamVR_Controller.Input((int)trackedObject.index);

        startSwitch = device.GetPress(Valve.VR.EVRButtonId.k_EButton_SteamVR_Touchpad);
        bikeLevers = device.GetPress(Valve.VR.EVRButtonId.k_EButton_SteamVR_Trigger);
        leftFoot = device.GetPress(Valve.VR.EVRButtonId.k_EButton_Grip);
        rightFoot = device.GetPress(Valve.VR.EVRButtonId.k_EButton_ApplicationMenu);
        if (i == 10)
        {
            up = Instantiate(empty, up.transform.position, up.transform.rotation, this.transform);

            down = Instantiate(empty, down.transform.position, down.transform.rotation, this.transform);

            left = Instantiate(empty, left.transform.position, left.transform.rotation, this.transform);

            right = Instantiate(empty, right.transform.position, right.transform.rotation, this.transform);

            distUp = Math.Distance(upDownController.transform.position, up.transform.position);

            distDown = Math.Distance(upDownController.transform.position, down.transform.position);

            distLeft = Math.Distance(leftRightController.transform.position, left.transform.position);

            distRight = Math.Distance(leftRightController.transform.position, right.transform.position);
            i++;

            
        }
        else if (i < 10) i++;

        //This turns the engine on or off,
        //if (vr_device.GetPress(startSwitch)) {
        if (Input.GetKeyDown(KeyCode.M)) {
            switch (engineOn)
            {
                case (true):
                    { engineOn = false; break; }
                case (false):
                    { engineOn = true; break; }
            }
        }

        //If the engine is on, this will set the speed of the bike, as wel as adjusting the pitch of the sound it makes.
        if (engineOn == true)
        {
            if (audioData.pitch < 0.5)
            {
                audioData.pitch += 1.0f * Time.deltaTime;
            }
            /*This is the code that decides acceleration and max speed, this allows 
             * for a variable speed depending on how far the throttle is open.*/

            acceleration = ((1 + Input.GetAxis("Throttle")) * accelerationMultiplier) * Time.deltaTime;
            maxSpeed = ((1 + Input.GetAxis("Throttle")) * maxSpeedMultiplier);
            //Debug.Log(Input.GetAxis("Throttle"));

        }
        else
        {
            if (audioData.pitch > 0.0)
            {
                audioData.pitch -= 1.0f * Time.deltaTime;
                acceleration = 0.0f;
                maxSpeed = 0.0f;

            }
        }

        distance = this.GetComponent<SplineWalkerPlayer>().distance;
        if (distance < radius)
        {
            if (Math.Distance(leftRightController.transform.position, left.transform.position) < distLeft - (distLeft / 100 * leanThreshhold))
            {
                leanAngle = (0 - Math.Distance(trackedObject.transform.position, left.transform.position)) * -1;
                leanAngle = (leanAngle - distLeft) * -1;

                Vector3 a = left.transform.position - trackedObject.transform.position;
                Math.NormVector(a);
                xzoffset -= (((a * movementAdjuster)*2) / 4) * (leanAngle * 1);
                xzoffset.y = 0;



            }
            if (Math.Distance(leftRightController.transform.position, right.transform.position) < distRight - (distRight / 100 * leanThreshhold))
            {
                leanAngle = (0 - Math.Distance(trackedObject.transform.position, right.transform.position)) * -1;
                leanAngle = (leanAngle - distRight) * -1;

                Vector3 a = right.transform.position - trackedObject.transform.position;
                Math.NormVector(a);
                xzoffset -= (((a * movementAdjuster)*2) / 4) * (leanAngle * 1);
                xzoffset.y = 0;
            }
            if (Math.Distance(upDownController.transform.position, up.transform.position) < distUp - (distUp / 100 * leanThreshhold))
            {
                pitchAngle = (0 - Math.Distance(trackedObject.transform.position, up.transform.position)) * -1;


                Vector3 a = up.transform.position - trackedObject.transform.position;
                Math.NormVector(a);
                yoffset += ((a * movementAdjuster) / 4) * (pitchAngle * 1);
                yoffset.x = 0;
                yoffset.z = 0;
            }
            if (Math.Distance(upDownController.transform.position, down.transform.position) < distDown - (distDown / 100 * leanThreshhold))
            {
                pitchAngle = (0 - Math.Distance(trackedObject.transform.position, down.transform.position)) * -1;


                Vector3 a = down.transform.position - trackedObject.transform.position;
                Math.NormVector(a);
                yoffset += ((a * movementAdjuster) / 4) * (pitchAngle * 1);
                yoffset.x = 0;
                yoffset.z = 0;
            }

            offset = xzoffset + yoffset;
        }
        else if (distance > (radius / 100) * 110)
        {
            offset = GetComponent<SplineWalkerPlayer>().moveToRadius(offset);

            xzoffset = offset;
            yoffset = offset;
            yoffset.x = 0;
            yoffset.z = 0;
            xzoffset.y = 0;
        }
        else
        {
            offset = GetComponent<SplineWalkerPlayer>().moveToCentre(offset);

            xzoffset = offset;
            yoffset = offset;
            yoffset.x = 0;
            yoffset.z = 0;
            xzoffset.y = 0;
        }


        if (speed < maxSpeed) speed += (acceleration * 2.0f) * Time.fixedDeltaTime;


        if (speed > 0) speed += slowDown * Time.fixedDeltaTime;

        if (speed > maxSpeed)
        {
            slowDown = speed / 2;
            speed -= slowDown * Time.fixedDeltaTime;
        }
        if (speed < 0) speed = 0;

        slowDown = 0;

        //This simlply makes the engine sound like it's reving faster as the speed goes up.
        if ((audioData.pitch >= 0.5f) && (audioData.pitch <= 1.0f) && (engineOn == true))
        {
            audioData.pitch = (0.5f + speed * Time.deltaTime);
        }
        if (audioData.pitch > 1.0f)
        {
            audioData.pitch = 1.0f;
        }

        if (debugTestSpeed == true)
        {
            maxSpeed = 200;
            if (speed < 200)
            {
                speed = 200;
                
            }
        }

        //THis is the code that moved the player with the values gathered.
        directionNormalzized.y = 0;
        if (maxSpeed < 0) { maxSpeed = 0; }
        if (acceleration < 0) { acceleration = 0; }

    }
    float GetDistance(Vector3 A,Vector3 B)
    {
        Vector3 D = (A - B);
        D.x = D.x * D.x;
        D.y = D.y * D.y;
        D.z = D.z * D.z;
        return Mathf.Sqrt(D.x + D.y + D.z);
    }
    public void SetRadius(int x)
    {
        switch (x)
        {
            case 0://HugLine
                radius = 10;
                break;
            case 1://tiny
                radius = 45;
                break;
            case 2://small
                radius = 90;
                break;
            case 3://medium
                radius = 180;
                break;
            case 4://large
                radius = 360;
                break;
            default://if no number, you dont it wrong and will default to medium
                break;     
        }
    }
    void OnDrawGizmosSelected()
    {
        // draws a wirefrane sphear to show the range of the spawner
        Gizmos.color = Color.white;
        Gizmos.DrawWireSphere(transform.position, radius);
    }
}


    