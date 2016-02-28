00001 /**
00002  * \addtogroup sys
00003  * @{
00004  */
00005 
00006 /**
00007  * \defgroup ctimer Callback timer
00008  * @{
00009  *
00010  * The ctimer module provides a timer mechanism that calls a specified
00011  * C function when a ctimer expires.
00012  *
00013  */
00014 
00015 /*
00016  * Copyright (c) 2006, Swedish Institute of Computer Science.
00017  * All rights reserved.
00018  *
00019  * Redistribution and use in source and binary forms, with or without
00020  * modification, are permitted provided that the following conditions
00021  * are met:
00022  * 1. Redistributions of source code must retain the above copyright
00023  *    notice, this list of conditions and the following disclaimer.
00024  * 2. Redistributions in binary form must reproduce the above copyright
00025  *    notice, this list of conditions and the following disclaimer in the
00026  *    documentation and/or other materials provided with the distribution.
00027  * 3. Neither the name of the Institute nor the names of its contributors
00028  *    may be used to endorse or promote products derived from this software
00029  *    without specific prior written permission.
00030  *
00031  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
00032  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
00033  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
00034  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
00035  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
00036  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
00037  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
00038  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
00039  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
00040  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
00041  * SUCH DAMAGE.
00042  *
00043  * This file is part of the Contiki operating system.
00044  *
00045  * $Id: ctimer.h,v 1.2 2010/06/14 07:35:53 adamdunkels Exp $
00046  */
00047 
00048 /**
00049  * \file
00050  *         Header file for the callback timer
00051  * \author
00052  *         Adam Dunkels <adam@sics.se>
00053  */
00054 
00055 #ifndef __CTIMER_H__
00056 #define __CTIMER_H__
00057 
00058 #include "sys/etimer.h"
00059 
00060 struct ctimer {
00061   struct ctimer *next;
00062   struct etimer etimer;
00063   struct process *p;
00064   void (*f)(void *);
00065   void *ptr;
00066 };
00067 
00068 /**
00069  * \brief      Reset a callback timer with the same interval as was
00070  *             previously set.
00071  * \param c    A pointer to the callback timer.
00072  *
00073  *             This function resets the callback timer with the same
00074  *             interval that was given to the callback timer with the
00075  *             ctimer_set() function. The start point of the interval
00076  *             is the exact time that the callback timer last
00077  *             expired. Therefore, this function will cause the timer
00078  *             to be stable over time, unlike the ctimer_restart()
00079  *             function.
00080  *
00081  * \sa ctimer_restart()
00082  */
00083 void ctimer_reset(struct ctimer *c);
00084 
00085 /**
00086  * \brief      Restart a callback timer from the current point in time
00087  * \param c    A pointer to the callback timer.
00088  *
00089  *             This function restarts the callback timer with the same
00090  *             interval that was given to the ctimer_set()
00091  *             function. The callback timer will start at the current
00092  *             time.
00093  *
00094  *             \note A periodic timer will drift if this function is
00095  *             used to reset it. For periodic timers, use the
00096  *             ctimer_reset() function instead.
00097  *
00098  * \sa ctimer_reset()
00099  */
00100 void ctimer_restart(struct ctimer *c);
00101 
00102 /**
00103  * \brief      Set a callback timer.
00104  * \param c    A pointer to the callback timer.
00105  * \param t    The interval before the timer expires.
00106  * \param f    A function to be called when the timer expires.
00107  * \param ptr  An opaque pointer that will be supplied as an argument to the callback function.
00108  *
00109  *             This function is used to set a callback timer for a time
00110  *             sometime in the future. When the callback timer expires,
00111  *             the callback function f will be called with ptr as argument.
00112  *
00113  */
00114 void ctimer_set(struct ctimer *c, clock_time_t t,
00115                 void (*f)(void *), void *ptr);
00116 
00117 /**
00118  * \brief      Stop a pending callback timer.
00119  * \param c    A pointer to the pending callback timer.
00120  *
00121  *             This function stops a callback timer that has previously
00122  *             been set with ctimer_set(), ctimer_reset(), or ctimer_restart().
00123  *             After this function has been called, the callback timer will be
00124  *             expired and will not call the callback function.
00125  *
00126  */
00127 void ctimer_stop(struct ctimer *c);
00128 
00129 /**
00130  * \brief      Check if a callback timer has expired.
00131  * \param c    A pointer to the callback timer
00132  * \return     Non-zero if the timer has expired, zero otherwise.
00133  *
00134  *             This function tests if a callback timer has expired and
00135  *             returns true or false depending on its status.
00136  */
00137 int ctimer_expired(struct ctimer *c);
00138 
00139 /**
00140  * \brief      Initialize the callback timer library.
00141  *
00142  *             This function initializes the callback timer library and
00143  *             should be called from the system boot up code.
00144  */
00145 void ctimer_init(void);
00146 
00147 #endif /* __CTIMER_H__ */
00148 /** @} */
00149 /** @} */